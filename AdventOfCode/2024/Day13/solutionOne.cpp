#include "solutionOne.h"

struct Question
{
    int buttonA_X;
    int buttonA_Y;
    int buttonB_X;
    int buttonB_Y;
    int targetX;
    int targetY;
};

constexpr int buttonACost = 3;
constexpr int buttonBCost = 1;

struct Answer
{
    int x;
    int y;
    bool operator==(const Answer &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator<(const Answer &other) const
    {
        auto costA = x * buttonACost + y * buttonBCost;
        auto costB = other.x * buttonACost + other.y * buttonBCost;
        return costA < costB;
    }
    int getCost()
    {
        return x * buttonACost + y * buttonBCost;
    }
};

struct AnswerHash
{
    std::size_t operator()(const Answer &ans) const
    {
        return std::hash<int>()(ans.x) * 31 + std::hash<int>()(ans.y);
    }
};

regex findNumbersPattern(R"(X[+=](\d+), Y[+=](\d+))");

std::tuple<int, int, int> extendedGCD(int a, int b)
{
    if (b == 0)
    {
        return {a, 1, 0};
    }
    auto [gcd, x1, y1] = extendedGCD(b, a % b);
    return {gcd, y1, x1 - (a / b) * y1};
}

std::vector<Answer> solveDiophantineEquation(int a, int b, int c)
{

    int gcd = std::gcd(a, b);
    if (c % gcd != 0)
    {
        return {};
    }

    auto [gcd_ext, x0, y0] = extendedGCD(a, b);

    x0 *= c / gcd;
    y0 *= c / gcd;

    std::vector<Answer> solutions;
    int b_div_gcd = b / gcd;
    int a_div_gcd = a / gcd;

    int k_min = std::ceil(-1.0 * x0 / b_div_gcd);
    int k_max = std::floor(1.0 * y0 / a_div_gcd);

    for (int k = k_min; k <= k_max; ++k)
    {
        int x = x0 + k * b_div_gcd;
        int y = y0 - k * a_div_gcd;
        if (x > 0 && y > 0)
        {
            solutions.push_back({x, y});
        }
    }

    return solutions;
}

std::vector<Answer> findIntersection(const std::vector<Answer> &solutionsX, const std::vector<Answer> &solutionsY)
{

    unordered_set<Answer, AnswerHash> set1(solutionsX.begin(), solutionsX.end());
    vector<Answer> result;

    for (const auto &solution : solutionsY)
    {
        if (set1.find(solution) != set1.end())
        {
            result.push_back(solution);
        }
    }

    return result;
}

vector<string> solutionOne(vector<string> const &input)
{
    vector<Question> questions;

    for (const auto &line : input)
    {

        if (line.starts_with("Button A:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern);
            auto question = Question();
            question.buttonA_X = stoi(match[1]);
            question.buttonA_Y = stoi(match[2]);
            questions.emplace_back(question);
        }
        else if (line.starts_with("Button B:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern);
            auto index = questions.size() - 1;
            questions[index].buttonB_X = stoi(match[1]);
            questions[index].buttonB_Y = stoi(match[2]);
        }
        else if (line.starts_with("Prize:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern);
            auto index = questions.size() - 1;
            questions[index].targetX = stoi(match[1]);
            questions[index].targetY = stoi(match[2]);
        }
    }
    long long totalTokens = 0;

    for (const auto &question : questions)
    {
        auto solutionsX = solveDiophantineEquation(question.buttonA_X, question.buttonB_X, question.targetX);
        auto solutionsY = solveDiophantineEquation(question.buttonA_Y, question.buttonB_Y, question.targetY);
        auto commonSolutions = findIntersection(solutionsX, solutionsY);
        sort(commonSolutions.begin(), commonSolutions.end());

        if (commonSolutions.size() > 0)
        {
            totalTokens += commonSolutions[0].getCost();
        }
    }

    return {to_string(totalTokens)};
}

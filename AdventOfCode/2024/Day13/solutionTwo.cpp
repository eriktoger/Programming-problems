#include "solutionTwo.h"

struct Answer2
{
    long long x;
    long long y;
    bool solved;
};

struct Question2
{
    long long a1;
    long long b1;
    long long a2;
    long long b2;
    long long c1;
    long long c2;

    Answer2 solve_system() const
    {
        long long detA = a1 * b2 - a2 * b1;
        if (detA == 0)
        {
            return Answer2(0, 0, false);
        }
        long long detAx = c1 * b2 - c2 * b1;
        long long detAy = a1 * c2 - a2 * c1;

        if (detAx % detA != 0 || detAy % detA != 0)
        {
            return Answer2(0, 0, false);
        }

        long long x = detAx / detA;
        long long y = detAy / detA;

        return Answer2(x, y, true);
    }
};

constexpr int buttonACost = 3;
constexpr int buttonBCost = 1;

regex findNumbersPattern2(R"(X[+=](\d+), Y[+=](\d+))");

vector<string> solutionTwo(vector<string> const &input)
{
    vector<Question2> questions;
    int numberOfProblems = (input.size() + 1) / 4;
    questions.reserve(numberOfProblems);

    size_t index = 0;

    for (const auto &line : input)
    {

        if (line.starts_with("Button A:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern2);
            auto question = Question2();
            questions.emplace_back(question);
            questions[index].a1 = stoll(match[1]);
            questions[index].a2 = stoll(match[2]);
        }
        else if (line.starts_with("Button B:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern2);

            questions[index].b1 = stoll(match[1]);
            questions[index].b2 = stoll(match[2]);
        }
        else if (line.starts_with("Prize:"))
        {
            std::smatch match;
            regex_search(line, match, findNumbersPattern2);

            questions[index].c1 = stoll(match[1]) + 10000000000000;
            questions[index].c2 = stoll(match[2]) + 10000000000000;

            index++;
        }
    }

    long long totalTokens = 0;

    for (const auto &question : questions)
    {

        auto answer = question.solve_system();
        if (answer.solved)
        {
            totalTokens += answer.x * buttonACost + answer.y * buttonBCost;
        }
    }

    return {to_string(totalTokens)};
}

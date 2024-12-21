#include "utils.h"

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate leftDirection = {0, -1};
constexpr Coordinate rightDirection = {0, 1};

constexpr array<Coordinate, 4> directions = {
    rightDirection,
    upDirection,
    downDirection,
    leftDirection,
};

Coordinate getDistance(Coordinate const &start, Coordinate const &end)
{
    return {end.row - start.row, end.col - start.col};
}

Coordinate getDirection(Coordinate const &start, Coordinate const &end)
{
    int row = 0;
    int col = 0;
    if (start.row < end.row)
    {
        row = -1;
    }
    else if (start.row > end.row)
    {
        row = 1;
    }

    if (start.col < end.col)
    {
        col = -1;
    }
    else if (start.col > end.col)
    {
        col = 1;
    }
    return {row, col};
}

char getDirecionToken(Coordinate const distance)
{

    if (distance.row == 1)
    {
        return 'v';
    }
    else if (distance.row == -1)
    {
        return '^';
    }
    else if (distance.col == 1)
    {
        return '>';
    }
    else if (distance.col == -1)
    {
        return '<';
    }
    return ' ';
}

struct State
{
    int cost;
    Coordinate coordinate;
    int directionIndex;
    vector<Coordinate> path;
    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};

unordered_map<string, string> cachedShortestPaths;

struct DPEntry
{
    int cost;
    vector<vector<Coordinate>> paths;
};

string findShortestPathInstructions(const unordered_map<char, Coordinate> &positions, char startButton, char endButton)
{
    string key = to_string(positions.size()) + "-" + startButton + "-" + endButton;

    if (cachedShortestPaths.contains(key))
    {
        return cachedShortestPaths.at(key);
    }

    auto startPosition = positions.at(startButton);
    auto endPosition = positions.at(endButton);

    vector<vector<vector<DPEntry>>> dp(4, vector<vector<DPEntry>>(4, vector<DPEntry>(4, {INT_MAX, {}})));

    priority_queue<State, vector<State>, greater<State>> pq;

    pq.emplace(0, startPosition);

    for (int dir = 0; dir < 4; ++dir)
    {
        dp[startPosition.row][startPosition.col][dir].cost = 0;
        dp[startPosition.row][startPosition.col][dir].paths.push_back({startPosition});
        pq.emplace(0, startPosition, dir, vector<Coordinate>{startPosition});
    }

    while (!pq.empty())
    {
        auto top = pq.top();
        auto currentCost = top.cost;
        auto row = top.coordinate.row;
        auto col = top.coordinate.col;
        auto directionIndex = top.directionIndex;
        auto path = top.path;

        pq.pop();
        auto isThereACheaperWay = dp[row][col][directionIndex].cost < currentCost;
        if (isThereACheaperWay)
        {
            continue;
        }

        for (int newDirection = 0; newDirection < directions.size(); newDirection++)
        {
            int newRow = row + directions[newDirection].row;
            int newCol = col + directions[newDirection].col;
            auto newPosition = Coordinate(newRow, newCol);
            bool newPositionExists = false;

            for (const auto &pair : positions)
            {
                if (pair.second == newPosition)
                {
                    newPositionExists = true;
                    break;
                }
            }

            if (!newPositionExists)
            {
                continue;
            }

            int additionalCost = (newDirection == directionIndex) ? 1 : 1001;
            int newCost = currentCost + additionalCost;

            vector<Coordinate> newPath = path;
            newPath.emplace_back(newPosition);

            auto isCheapestPath = newCost < dp[newRow][newCol][newDirection].cost;
            auto isEqualCostPath = newCost == dp[newRow][newCol][newDirection].cost;
            if (isCheapestPath)
            {
                dp[newRow][newCol][newDirection].cost = newCost;
                dp[newRow][newCol][newDirection].paths = {newPath};
                pq.emplace(newCost, newPosition, newDirection, newPath);
            }
            else if (isEqualCostPath)
            {
                dp[newRow][newCol][newDirection].paths.push_back(newPath);
                pq.emplace(newCost, newPosition, newDirection, newPath);
            }
        }
    }

    string instructions;

    int minCost = INT_MAX;
    vector<vector<Coordinate>> bestPaths;

    for (int dir = 0; dir < 4; ++dir)
    {
        if (dp[endPosition.row][endPosition.col][dir].cost < minCost)
        {
            minCost = dp[endPosition.row][endPosition.col][dir].cost;
            bestPaths = dp[endPosition.row][endPosition.col][dir].paths;
        }
    }
    auto currentPosition = startPosition;
    vector<Coordinate> bestPath;

    for (const auto &path : bestPaths)
    {
        if (path.empty())
        {
            continue;
        }

        if (path[0] != startPosition)
        {
            continue;
        }

        if (path[path.size() - 1] != endPosition)
        {
            continue;
        }

        if (path.size() < bestPath.size() || bestPath.empty())
        {
            bestPath = path;
        }
    }

    for (const auto &newPosition : bestPath)
    {

        if (newPosition == startPosition)
        {
            continue;
        }

        auto distance = getDistance(currentPosition, newPosition);
        instructions += getDirecionToken(distance);
        currentPosition = newPosition;
    }

    cachedShortestPaths.insert({key, instructions});

    return instructions;
}

string generateCacheKey(char startToken, char endToken)
{
    string key = "";
    key += startToken;
    key += "-";
    key += endToken;
    return key;
}

// jag behöver nog kolla vad < ^ v > A blir var för sig?
// för varje level så < 0, ^ 1 osv och börja från level 25?
// som jag gjorde för något problem sedan.

vector<char> dirTokens = {'<', '^', 'v', '>', 'A'};

vector<string> solverWithCache(vector<string> const &input, int nrOfDirPadBots)
{
    auto numPadRobot = NumPadRobot{};
    numPadRobot.dirPadRobots = vector<DirPadRobot>(nrOfDirPadBots);
    vector<unordered_map<string, unsigned long long>> cachedDirPadLengths(nrOfDirPadBots);

    auto cacheGeneratorBot = DirPadRobot{};
    cacheGeneratorBot.currentButton = 'A';
    auto &baseLevel = cachedDirPadLengths[0];
    for (auto startToken : dirTokens)
    {
        for (auto endToken : dirTokens)
        {
            cacheGeneratorBot.currentButton = startToken;
            std::string endString(1, endToken);
            auto instructions = cacheGeneratorBot.getInstructions(endString);
            auto key = generateCacheKey(startToken, endToken);
            baseLevel.insert({key, instructions.size()});
        }
    }

    for (int index = 1; index < nrOfDirPadBots; index++)
    {
        auto &previousLevel = cachedDirPadLengths[index - 1];
        auto &currentLevel = cachedDirPadLengths[index];
        for (auto startToken : dirTokens)
        {
            for (auto endToken : dirTokens)
            {
                cacheGeneratorBot.currentButton = startToken;
                string endString(1, endToken);
                auto instructions = cacheGeneratorBot.getInstructions(endString);

                auto totalLength = 0ull;
                auto tempStartToken = 'A'; // Im not sure about this
                for (auto token : instructions)
                {
                    auto prevKey = generateCacheKey(tempStartToken, token);
                    totalLength += previousLevel.at(prevKey);
                    tempStartToken = token;
                }

                auto key = generateCacheKey(startToken, endToken);
                currentLevel.insert({key, totalLength});
            }
        }
    }

    numPadRobot.cachedDirPadLengths = cachedDirPadLengths;
    auto totalComplexity = 0ull;
    for (const auto &line : input)
    {
        numPadRobot.currentButton = 'A';
        for (auto &dirPadRobot : numPadRobot.dirPadRobots)
        {
            dirPadRobot.currentButton = 'A';
        }

        auto length = numPadRobot.getInstructionsWithCache(line);

        unsigned long long numericPart = stoi(line.substr(0, 3));
        unsigned long long complexity = length * numericPart;
        totalComplexity += complexity;
    }

    return {to_string(totalComplexity)};
}

vector<string> solver(vector<string> const &input, int nrOfDirPadBots)
{
    auto numPadRobot = NumPadRobot{};
    numPadRobot.dirPadRobots = vector<DirPadRobot>(nrOfDirPadBots);

    auto totalComplexity = 0ull;
    for (const auto &line : input)
    {
        numPadRobot.currentButton = 'A';
        for (auto &dirPadRobot : numPadRobot.dirPadRobots)
        {
            dirPadRobot.currentButton = 'A';
        }

        auto instructions = numPadRobot.getInstructions(line);

        auto numericPart = stoi(line.substr(0, 3));
        auto complexity = instructions.size() * numericPart;
        totalComplexity += complexity;
    }

    return {to_string(totalComplexity)};
}

// too high: 248737376587816
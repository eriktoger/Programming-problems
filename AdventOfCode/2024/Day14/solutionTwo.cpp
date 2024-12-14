#include "solutionTwo.h"

void printGrid(const vector<vector<char>> &grid)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
    }
}

vector<int> findIntersection(vector<int> possibleRows, vector<int> possibleCols)
{
    sort(possibleRows.begin(), possibleRows.end());
    std::sort(possibleCols.begin(), possibleCols.end());

    std::vector<int> intersection;

    std::set_intersection(possibleRows.begin(), possibleRows.end(),
                          possibleCols.begin(), possibleCols.end(),
                          std::back_inserter(intersection));

    return intersection;
}

int findMostFrequentNumber(const vector<vector<int>> &possibleAnswers)
{

    unordered_map<int, int> frequencyMap;

    for (auto &possibleAnswer : possibleAnswers)
    {
        for (int num : possibleAnswer)
        {
            frequencyMap[num]++;
        }
    }

    int mostFrequent = -1;
    int maxCount = 0;

    for (const auto &pair : frequencyMap)
    {
        if (pair.second > maxCount)
        {
            mostFrequent = pair.first;
            maxCount = pair.second;
        }
    }

    return mostFrequent;
}

struct CoordniateHash
{
    std::size_t operator()(const Coordinate &ans) const
    {
        return std::hash<int>()(ans.x) * 31 + std::hash<int>()(ans.y);
    }
};

void findCols(const vector<vector<char>> &grid, vector<int> &possibleColAnswers, int iteration, int countLimit)
{
    for (auto row : grid)
    {
        int count = 0;
        for (auto col : row)
        {
            if (col == '#')
            {
                count++;
            }
        }

        if (count > countLimit)
        {
            possibleColAnswers.emplace_back(iteration);
            // cout << "Iteration: " << i + 1 << endl;
            // printGrid(grid);
            //  std::getline(std::cin, readLine);
            //   I found it on iteration: 8270
        }
    }
}

void findRows(const vector<vector<char>> &grid, vector<int> &possibleRowAnswers, int iteration, int countLimit)
{
    for (size_t col = 0; col < grid[0].size(); col++)
    {
        int rowCount = 0;
        for (size_t row = 0; row < grid.size(); row++)
        {
            if (grid[row][col] == '#')
            {
                rowCount++;
            }
        }
        if (rowCount > countLimit)
        {
            possibleRowAnswers.emplace_back(iteration);
        }
    }
}

void findDiagonals(const vector<vector<char>> &grid, vector<int> &possibleDiagonalAnswers, int iteration, int diagonalCountLimit)
{
    unordered_map<Coordinate, bool, CoordniateHash> visitiedRightDownCoordinates;
    unordered_map<Coordinate, bool, CoordniateHash> visitiedLeftDownCoordinates;

    for (int row = 0; row < grid.size() - diagonalCountLimit; row++)
    {
        for (int col = 0; col < grid[0].size() - diagonalCountLimit; col++)
        {
            auto isAToken = grid[row][col] == '#';

            if (isAToken)
            {
                int rightDowndiagonalCount = 0;
                auto currentRow = row;
                auto currentCol = col;
                vector<Coordinate> rightDownDiagonalCoordinates;
                auto rightDownAlradyCounted = visitiedRightDownCoordinates.contains(Coordinate{row, col});
                while (currentRow < grid.size() && currentCol < grid[0].size() && !rightDownAlradyCounted)
                {
                    if (grid[currentRow][currentCol] == '#')
                    {
                        rightDowndiagonalCount++;
                        rightDownDiagonalCoordinates.emplace_back(Coordinate{currentRow, currentCol});
                    }
                    else
                    {
                        break;
                    }
                    currentRow++;
                    currentCol++;
                }

                if (rightDowndiagonalCount > diagonalCountLimit)
                {
                    possibleDiagonalAnswers.emplace_back(iteration);
                    for (const auto &coord : rightDownDiagonalCoordinates)
                    {
                        visitiedRightDownCoordinates[coord] = true;
                    }
                }

                int leftDowndiagonalCount = 0;
                currentRow = row;
                currentCol = col;
                vector<Coordinate> leftDownDiagonalCoordinates;
                auto leftDownAlreadyCounted = visitiedLeftDownCoordinates.contains(Coordinate{row, col});
                while (!leftDownAlreadyCounted)
                {
                    if (grid[currentRow][currentCol] == '#')
                    {
                        leftDowndiagonalCount++;
                        leftDownDiagonalCoordinates.emplace_back(Coordinate{currentRow, currentCol});
                    }
                    else
                    {
                        break;
                    }

                    if (currentRow == 0 || currentCol == grid[0].size() - 1)
                    {
                        break;
                    }
                    currentRow--;
                    currentCol++;
                }

                if (leftDowndiagonalCount > diagonalCountLimit)
                {
                    possibleDiagonalAnswers.emplace_back(iteration);
                    for (const auto &coord : leftDownDiagonalCoordinates)
                    {
                        visitiedLeftDownCoordinates[coord] = true;
                    }
                }
            }
        }
    }
}

vector<Coordinate> directions = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void findSquares(const vector<vector<char>> &grid, vector<int> &possibleSquareAnswers, int iteration)
{
    for (int row = 1; row < grid.size() - 1; row++)
    {
        for (int col = 1; col < grid[0].size() - 1; col++)
        {
            auto isSquare = all_of(directions.begin(), directions.end(), [&grid, row, col](const auto &direction)
                                   { return grid[row + direction.y][col + direction.x] == '#'; });

            if (isSquare)
            {
                possibleSquareAnswers.emplace_back(iteration);
            }
        }
    }
}

vector<string> solutionTwo(vector<string> const &input)
{

    vector<Robot> robots;
    vector<long long> quadrantCounts{0, 0, 0, 0};

    for (const auto &line : input)
    {
        smatch match;
        regex_search(line, match, numbersPattern);
        auto position = Coordinate{stoi(match[1]), stoi(match[2])};
        auto direction = Coordinate{stoi(match[3]), stoi(match[4])};
        auto robot = Robot{position, direction, -1};

        robots.emplace_back(robot);
    }

    vector<vector<char>> grid;
    for (int row = 0; row < height; row++)
    {
        vector<char> currentRow;
        for (int col = 0; col < width; col++)
        {
            currentRow.emplace_back(' ');
        }
        grid.emplace_back(currentRow);
    }

    std::string readLine;

    vector<int> possibleRowAnswers;
    vector<int> possibleColAnswers;
    vector<int> possibleDiagonalAnswers;
    vector<int> possibleSquareAnswers;

    int countLimit = 30;
    int diagonalCountLimit = 10;
    for (int i = 0; i < 15000; i++)
    {

        for (auto &robot : robots)
        {
            robot.move(1);
            grid[robot.position.y][robot.position.x] = '#';
        }

        auto iteration = i + 1;
        findCols(grid, possibleColAnswers, iteration, countLimit);

        findRows(grid, possibleRowAnswers, iteration, countLimit);

        findDiagonals(grid, possibleDiagonalAnswers, iteration, diagonalCountLimit);

        findSquares(grid, possibleSquareAnswers, iteration);

        for (auto &robot : robots)
        {
            grid[robot.position.y][robot.position.x] = ' ';
        }
    }
    vector<vector<int>> possibleAnswers = {possibleRowAnswers, possibleColAnswers, possibleDiagonalAnswers, possibleSquareAnswers};
    auto answer = findMostFrequentNumber(possibleAnswers);
    return {to_string(answer)};
}

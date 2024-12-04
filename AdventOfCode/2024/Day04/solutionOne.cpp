#include "solutionOne.h"

vector<char> word = {'X', 'M', 'A', 'S'};

struct Coordinate
{
    int rowDirection;
    int colDirection;
};

vector<Coordinate> directions = {
    {1, 0},   // Down
    {-1, 0},  // Left
    {0, 1},   // Right
    {0, -1},  // Up
    {-1, 1},  // Up-Right
    {-1, -1}, // Up-Left
    {1, 1},   // Down-Right
    {1, -1},  // Down-Left
};

bool wordFound(vector<string> const &input, int rowIndex, int colIndex, int rowDirection, int colDirection)
{

    for (size_t i = 0; i < word.size(); i++)
    {
        int newRowIndex = rowIndex + i * rowDirection;
        int newColIndex = colIndex + i * colDirection;
        auto isOutOfBound = newRowIndex < 0 || newRowIndex >= input.size() || newColIndex < 0 || newColIndex >= input[newRowIndex].size();

        if (isOutOfBound || input[newRowIndex][newColIndex] != word[i])
        {
            return false;
        }
    }

    return true;
}

vector<string> solutionOne(vector<string> const &input)
{
    int wordCounter = 0;
    for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++)
    {
        auto row = input[rowIndex];
        for (size_t colIndex = 0; colIndex < row.size(); colIndex++)
        {
            for (auto const &direction : directions)
            {
                if (wordFound(input, rowIndex, colIndex, direction.rowDirection, direction.colDirection))
                {
                    wordCounter++;
                }
            }
        }
    }

    return {to_string(wordCounter)};
}

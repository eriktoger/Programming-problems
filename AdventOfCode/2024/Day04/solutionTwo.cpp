#include "solutionTwo.h"

struct Coordinate
{
    int row;
    int col;
};

struct Diagonal
{
    Coordinate corner;
    Coordinate oppositeCorner;
};

vector<Diagonal> diagonals = {
    {{-1, -1}, {1, 1}}, // upper left to lower right
    {{-1, 1}, {1, -1}}, // upper right to lower left
};

bool crossFound(vector<string> const &input, int rowIndex, int colIndex)
{

    bool wrongCenter = input[rowIndex][colIndex] != 'A';
    bool isOutOfBound = rowIndex < 1 || rowIndex > input.size() - 2 || colIndex < 1 || colIndex > input[rowIndex].size() - 2;
    if (wrongCenter || isOutOfBound)
    {
        return false;
    }

    auto isValidDiagonal = [input, rowIndex, colIndex](const Diagonal &diagonal)
    {
        char corner = input[rowIndex + diagonal.corner.row][colIndex + diagonal.corner.col];
        char oppositeCorner = input[rowIndex + diagonal.oppositeCorner.row][colIndex + diagonal.oppositeCorner.col];
        return (corner == 'M' && oppositeCorner == 'S') || (corner == 'S' && oppositeCorner == 'M');
    };

    return std::all_of(
        std::begin(diagonals),
        std::end(diagonals),
        isValidDiagonal);
}

vector<string> solutionTwo(vector<string> const &input)
{
    int wordCounter = 0;
    for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++)
    {
        auto row = input[rowIndex];
        for (size_t colIndex = 0; colIndex < row.size(); colIndex++)
        {
            if (crossFound(input, rowIndex, colIndex))
            {
                wordCounter++;
            }
        }
    }

    return {to_string(wordCounter)};
}

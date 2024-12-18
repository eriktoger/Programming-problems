#include "solutionTwo.h"

void updateBites(Board &board, int mid, char token)
{
    for (int i = 0; i < mid; i++)
    {
        auto coordinate = board.coordinates[i];
        board.grid[coordinate.row][coordinate.col] = token;
    }
}

void fillBoard(Board &board, int mid)
{
    updateBites(board, mid, wallToken);
}

void resetBoard(Board &board, int mid)
{
    updateBites(board, mid, freeToken);
}

vector<string> solutionTwo(vector<string> const &input)
{
    auto board = generateBoard(input);

    int lowerLimit = 0;
    int upperLimit = board.height == 70 ? 3450 : 24;

    while (upperLimit - lowerLimit > 1)
    {
        auto mid = (upperLimit + lowerLimit) / 2;

        fillBoard(board, mid);

        auto steps = solver(board.grid, board.width, board.height);

        if (steps == INT_MAX)
        {
            upperLimit = mid;
        }
        else
        {
            lowerLimit = mid;
        }

        resetBoard(board, mid);
    }

    auto coordinate = board.coordinates[lowerLimit];
    string answer;
    answer += to_string(coordinate.col);
    answer += ",";
    answer += to_string(coordinate.row);

    return {answer};
}

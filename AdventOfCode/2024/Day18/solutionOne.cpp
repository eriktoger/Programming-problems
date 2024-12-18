#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    auto board = generateBoard(input);

    auto nrOfBites = board.height == 70 ? 1024 : 12;
    for (int i = 0; i < nrOfBites; i++)
    {
        auto coordinate = board.coordinates[i];
        board.grid[coordinate.row][coordinate.col] = wallToken;
    }

    auto steps = solver(board.grid, board.width, board.height);

    return {to_string(steps)};
}

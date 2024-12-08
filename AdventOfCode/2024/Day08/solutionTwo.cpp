#include "solutionTwo.h"

void findAntiNodes(const Coordinate &coordinate, set<string> &antiNodes, vector<string> const &input, int distRow, int distCol, int direction)
{
    int steps = 0;
    while (true)
    {

        int antiNodeRow = coordinate.row + distRow * steps * direction;
        int antiNodeCol = coordinate.col + distCol * steps * direction;

        if (!isInBounds(input, antiNodeRow, antiNodeCol))
        {
            break;
        }

        string key = to_string(antiNodeRow) + "," + to_string(antiNodeCol);
        antiNodes.insert(key);
        steps++;
    }
}

vector<string> solutionTwo(vector<string> const &input)
{
    unordered_map<char, vector<Coordinate>> antennas;
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < input[i].size(); j++)
        {
            auto token = input[i][j];
            if (token != '.' && token != '#')
            {
                antennas[token].emplace_back(i, j);
            }
        }
    }

    set<string> antiNodes;
    for (auto const &antenna : antennas)
    {
        auto coordinates = antenna.second;
        for (size_t i = 0; i < coordinates.size(); i++)
        {
            for (size_t j = i + 1; j < coordinates.size(); j++)
            {
                int distRow = coordinates[i].row - coordinates[j].row;
                int distCol = coordinates[i].col - coordinates[j].col;

                findAntiNodes(coordinates[i], antiNodes, input, distRow, distCol, 1);
                findAntiNodes(coordinates[j], antiNodes, input, distRow, distCol, -1);
            }
        }
    }

    return {to_string(antiNodes.size())};
}

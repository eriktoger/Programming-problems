#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    unordered_map<char, vector<Coordinate>> antennas;
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] != '.' && input[i][j] != '#')
            {
                Coordinate coordinate = {i, j};
                antennas[input[i][j]].emplace_back(coordinate);
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

                int antiNode1Row = coordinates[i].row + distRow;
                int antiNode1Col = coordinates[i].col + distCol;

                if (isInBounds(input, antiNode1Row, antiNode1Col))
                {
                    string key = to_string(antiNode1Row) + "," + to_string(antiNode1Col);
                    antiNodes.insert(key);
                }

                int antiNode2Row = coordinates[j].row - distRow;
                int antiNode2Col = coordinates[j].col - distCol;

                if (isInBounds(input, antiNode2Row, antiNode2Col))
                {
                    string key = to_string(antiNode2Row) + "," + to_string(antiNode2Col);
                    antiNodes.insert(key);
                }
            }
        }
    }

    return {to_string(antiNodes.size())};
}

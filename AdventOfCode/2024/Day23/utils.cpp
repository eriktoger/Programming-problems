#include "utils.h"

map<string, set<string>> generateNodes(vector<string> const &input)
{
    map<string, set<string>> nodes;

    for (const auto &line : input)
    {
        std::smatch match;
        regex_search(line, match, pattern);
        auto node1 = match[1];
        auto node2 = match[2];

        if (nodes.contains(node1))
        {
            nodes.at(node1).insert(node2);
        }
        else
        {
            nodes[node1] = {node2};
        }

        if (nodes.contains(node2))
        {
            nodes.at(node2).insert(node1);
        }
        else
        {
            nodes[node2] = {node1};
        }
    }
    return nodes;
}
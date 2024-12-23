#include "solutionOne.h"

std::regex pattern("([a-z]{2})-([a-z]{2})");

struct Node
{
    string name;
    vector<Node> connections;
};

vector<string> solutionOne(vector<string> const &input)
{
    map<string, vector<string>> nodes;

    for (const auto &line : input)
    {
        std::smatch match;
        regex_search(line, match, pattern);
        auto node1 = match[1];
        auto node2 = match[2];

        if (nodes.contains(node1))
        {
            nodes.at(node1).push_back(node2);
        }
        else
        {
            nodes[node1] = {node2};
        }

        if (nodes.contains(node2))
        {
            nodes.at(node2).push_back(node1);
        }
        else
        {
            nodes[node2] = {node1};
        }
    }

    set<string> threeClusters;
    for (const auto &[nodeName, connections] : nodes)
    {
        if (!nodeName.starts_with("t"))
        {
            continue;
        }

        for (const auto &connection : connections)
        {
            if (connection == nodeName)
            {
                continue;
            }

            for (const auto &connection2 : nodes.at(connection))
            {
                if (connection2 == nodeName || connection2 == connection || find(connections.begin(), connections.end(), connection2) == connections.end())
                {
                    continue;
                }
                vector names = {nodeName, connection, connection2};
                sort(names.begin(), names.end());

                string cluster = names[0] + "-" + names[1] + "-" + names[2];
                threeClusters.insert(cluster);
            }
        }
    }

    return {to_string(threeClusters.size())};
}

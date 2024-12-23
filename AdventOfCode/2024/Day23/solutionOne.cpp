#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    auto nodes = generateNodes(input);

    set<set<string>> threeClusters;
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
                if (connection2 == nodeName || connection2 == connection || !connections.contains(connection2))
                {
                    continue;
                }
                set<string> names{nodeName, connection, connection2};
                threeClusters.insert(names);
            }
        }
    }

    return {to_string(threeClusters.size())};
}

#include "solutionTwo.h"

string join_with_comma(const set<string> &cluster)
{
    return accumulate(cluster.begin(), cluster.end(), string(),
                      [](const string &a, const string &b) -> string
                      {
                          return a + (a.length() > 0 ? "," : "") + b;
                      });
}

void recursiveSearch(const map<string, set<string>> &nodes, string currentNode, set<string> cluster, set<string> &largestCluster, set<string> &serchedClusters)
{
    auto key = join_with_comma(cluster);
    if (serchedClusters.contains(key))
    {
        return;
    }

    serchedClusters.insert(key);

    if (cluster.size() > largestCluster.size())
    {
        largestCluster = cluster;
    }

    const auto &connections = nodes.at(currentNode);
    for (const auto &childNode : connections)
    {
        if (cluster.contains(childNode))
        {
            continue;
        }

        const auto &childConnections = nodes.at(childNode);
        auto isAddable = true;

        for (const auto &clusterNode : cluster)
        {
            if (!childConnections.contains(clusterNode))
            {
                isAddable = false;
                break;
            }
        }

        if (isAddable)
        {
            cluster.insert(childNode);
            recursiveSearch(nodes, childNode, cluster, largestCluster, serchedClusters);
        }
    }
}

vector<string> solutionTwo(vector<string> const &input)
{
    auto nodes = generateNodes(input);

    set<string> largestCluster;
    set<string> serchedClusters;

    for (const auto &[nodeName, connections] : nodes)
    {
        recursiveSearch(nodes, nodeName, {nodeName}, largestCluster, serchedClusters);
    }

    return {join_with_comma(largestCluster)};
}

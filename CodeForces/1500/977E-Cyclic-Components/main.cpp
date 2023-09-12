#include "main.h"
#include <map>
#include <vector>
#include <set>

enum class NodeStatus
{
    Failed = -1,
    NotVisited = 0,
    Success = 1
};

void func(std::istream &is, std::ostream &os)
{
    int nrOfVerticies;
    int nrOfEdges;

    is >> nrOfVerticies;
    is >> nrOfEdges;

    map<int, vector<int>> graph;
    set<int> verticies;

    while (nrOfEdges--)
    {
        int node1;
        int node2;
        is >> node1;
        is >> node2;
        verticies.emplace(node1);
        verticies.emplace(node2);
        if (graph.contains(node1))
        {
            graph.at(node1).emplace_back(node2);
        }
        else
        {
            graph.insert({node1, {node2}});
        }
        if (graph.contains(node2))
        {
            graph.at(node2).emplace_back(node1);
        }
        else
        {
            graph.insert({node2, {node1}});
        }
    }
    NodeStatus globalVisited[200001] = {NodeStatus::NotVisited};
    int cycles = 0;

    for (auto vertex : verticies)
    {
        if (globalVisited[vertex] != NodeStatus::NotVisited)
        {
            continue;
        }
        globalVisited[vertex] = NodeStatus::Success;
        auto edges = graph.at(vertex);
        if (edges.size() != 2 || globalVisited[edges[0]] != NodeStatus::NotVisited || globalVisited[edges[1]] != NodeStatus::NotVisited)
        {
            globalVisited[vertex] = NodeStatus::Failed;
            for (auto edge : edges)
            {
                globalVisited[edge] = NodeStatus::Failed;
            }
            continue;
        }
        long unsigned index = 0;
        auto onlyTwos = true;
        while (index < edges.size())
        {
            auto currentEdges = graph.at(edges[index]);

            if (currentEdges.size() == 2 &&
                globalVisited[currentEdges[0]] != NodeStatus::Failed &&
                globalVisited[currentEdges[1]] != NodeStatus::Failed)
            {
                if (globalVisited[currentEdges[0]] == NodeStatus::NotVisited)
                {
                    edges.emplace_back(currentEdges[0]);
                }

                globalVisited[currentEdges[0]] = NodeStatus::Success;

                if (globalVisited[currentEdges[1]] == NodeStatus::NotVisited)
                {
                    edges.emplace_back(currentEdges[1]);
                }

                globalVisited[currentEdges[1]] = NodeStatus::Success;
            }
            else
            {
                for (auto edge : edges)
                {
                    globalVisited[edge] = NodeStatus::Failed;
                }
                onlyTwos = false;
                break;
            }

            index++;
        }

        if (onlyTwos)
        {
            cycles++;
        }
    }
    os << cycles;
}

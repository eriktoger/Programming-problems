#include "main.h"

class Node
{
public:
    int id = 0;
    vector<int> edges;
    bool visited = false;

    Node(int id) : id(id) {}
};

Node &getNode(map<int, Node> &nodes, int id)
{
    return nodes.find(id)->second;
}

map<int, Node> getNodes(std::istream &is, int nrOfEdges)
{
    map<int, Node> nodes;

    while (nrOfEdges--)
    {
        int firstNodeId;
        is >> firstNodeId;
        int secondNodeId;
        is >> secondNodeId;

        if (nodes.count(firstNodeId))
        {
            getNode(nodes, firstNodeId).edges.emplace_back(secondNodeId);
        }
        else
        {
            nodes.emplace(firstNodeId, Node(firstNodeId));
            getNode(nodes, firstNodeId).edges.emplace_back(secondNodeId);
        }

        if (nodes.count(secondNodeId))
        {
            getNode(nodes, secondNodeId).edges.emplace_back(firstNodeId);
        }
        else
        {
            nodes.emplace(secondNodeId, Node(secondNodeId));
            getNode(nodes, secondNodeId).edges.emplace_back(firstNodeId);
        }
    }

    return nodes;
}

int findNrOfConnectedNodes(map<int, Node> &nodes, int targetNodeId)
{
    auto &targetNode = getNode(nodes, targetNodeId);
    targetNode.visited = true;
    auto edgesToVisit = targetNode.edges;

    size_t edgeIndex = 0;
    while (edgeIndex < edgesToVisit.size())
    {
        auto currentNodeId = edgesToVisit[edgeIndex];
        auto &currentNode = getNode(nodes, currentNodeId);
        if (currentNode.visited == false)
        {
            currentNode.visited = true;
            for (auto neighbourNodeId : currentNode.edges)
            {
                auto &neighbourNode = getNode(nodes, neighbourNodeId);
                if (neighbourNode.visited == false)
                {
                    edgesToVisit.emplace_back(neighbourNode.id);
                }
            }
        }
        edgeIndex++;
    }
    return edgesToVisit.size();
}

const string player1 = "Ayush\n";
const string player2 = "Ashish\n";

void solution(std::istream &is, std::ostream &os)
{
    int testcases;
    is >> testcases;

    while (testcases--)
    {
        int nrOfNodes;
        int targetNodeId;
        is >> nrOfNodes;
        is >> targetNodeId;

        auto nodes = getNodes(is, nrOfNodes - 1);
        bool isTargetLeafNode = getNode(nodes, targetNodeId).edges.size() < 2;
        auto nrOfConnectedNodes = findNrOfConnectedNodes(nodes, targetNodeId);

        bool oddNrOfConnectedNodes = nrOfConnectedNodes % 2 != 0;
        if (isTargetLeafNode || oddNrOfConnectedNodes)
        {
            os << player1;
        }
        else
        {
            os << player2;
        }
    }
}

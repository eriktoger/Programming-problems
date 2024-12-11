#include "solutionOne.h"

struct Node
{
    long long value;
    shared_ptr<Node> next;
    long long children;
};

vector<string> solutionOne(vector<string> const &input)
{
    auto lines = splitLinesToWords(input);
    auto stones = lines[0];
    auto head = make_shared<Node>();
    long long value = stoll(stones[0]);
    head->value = value;

    // 17
    // 1 motsvarar 7545, 7 motsvarar 344834

    // initalize the linked list
    auto prevNode = head;

    // cound the nodes

    for (size_t i = 1; i < stones.size(); i++)
    {
        auto currentNode = make_shared<Node>();
        currentNode->value = stoll(stones[i]);
        prevNode->next = currentNode;
        prevNode = currentNode;
    }

    for (int rounds = 0; rounds < 25; rounds++)
    {
        auto currentNode = head;
        while (true)
        {
            if (currentNode->value == 0)
            {
                currentNode->value = 1;
            }
            else if (currentNode->value == 1)
            {
                currentNode->value = 2024;
            }
            else if (to_string(currentNode->value).size() % 2 == 0)
            {
                auto str = to_string(currentNode->value);
                auto half = str.size() / 2;
                auto firstHalf = str.substr(0, half);
                auto secondHalf = str.substr(half);
                currentNode->value = stoll(firstHalf);
                auto newNode = make_shared<Node>();
                newNode->value = stoll(secondHalf);

                newNode->next = currentNode->next;
                currentNode->next = newNode;
                currentNode = newNode;
            }
            else
            {

                currentNode->value *= 2024;
            }

            currentNode = currentNode->next;
            if (currentNode == nullptr)
            {
                break;
            }
        }
    }

    long long nodeCounter = 0;
    auto currentNode = head;
    while (true)
    {
        nodeCounter++;
        auto temp = currentNode;
        currentNode = currentNode->next;
        temp->next = nullptr;
        if (currentNode == nullptr)
        {
            break;
        }
    }

    return {to_string(nodeCounter)};
}

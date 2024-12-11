#include "solutionTwo.h"

struct Node
{
    long long value;
    shared_ptr<Node> next;
    long long childrenCount = 1;
};

long long solver(vector<string> const &input, map<string, long long> &cache, int roundsLimit)
{

    auto lines = splitLinesToWords(input);
    auto stones = lines[0];
    auto head = make_shared<Node>();
    long long value = stoll(stones[0]);
    head->value = value;
    head->childrenCount = 1;

    auto prevNode = head;

    for (size_t i = 1; i < stones.size(); i++)
    {
        auto currentNode = make_shared<Node>();
        currentNode->value = stoll(stones[i]);
        currentNode->childrenCount = 1;
        prevNode->next = currentNode;
        prevNode = currentNode;
    }

    for (int rounds = 0; rounds < roundsLimit; rounds++)
    {
        auto currentNode = head;

        while (true)
        {

            bool isNodeHandled = currentNode->childrenCount > 1;
            if (isNodeHandled)
            {
                currentNode = currentNode->next;
                if (currentNode == nullptr)
                {
                    break;
                }
                continue;
            }

            int roundsLeft = roundsLimit - rounds;
            auto value = currentNode->value;
            string key = to_string(value) + "-" + to_string(roundsLeft);

            if (cache.contains(key))
            {
                auto cachedValue = cache.at(key);
                currentNode->childrenCount = cachedValue;

                currentNode = currentNode->next;
                if (currentNode == nullptr)
                {
                    break;
                }
                continue;
            }

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
                newNode->childrenCount = 1;

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

        nodeCounter += currentNode->childrenCount;
        auto temp = currentNode;
        currentNode = currentNode->next;
        temp->next = nullptr;
        if (currentNode == nullptr)
        {
            break;
        }
    }

    string key = input[0] + "-" + to_string(roundsLimit);
    cache.insert(make_pair(key, nodeCounter));

    return nodeCounter;
}

vector<string> solutionTwo(vector<string> const &input)
{
    map<string, long long> cache;
    vector<string> baseCases{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (int i = 0; i < 75; i++)
    {
        for (auto baseCase : baseCases)
        {
            auto currentBaseCase = {baseCase};
            solver(currentBaseCase, cache, i + 1);
        }
    }

    long long sum = solver(input, cache, 75);
    return {to_string(sum)};
}
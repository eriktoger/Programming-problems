#include "main.h"

using namespace std;

int cycles = 10000;
int main()
{

    auto input = fromFileToVector("files/input.txt");

    auto durationRecursive = std::chrono::duration_cast<std::chrono::microseconds>(0ms);
    for (int i = 0; i < cycles; i++)
    {
        auto startRecursive = std::chrono::high_resolution_clock::now();
        auto outputRecursive = solutionTwoRecursive(input);
        auto endRecursive = std::chrono::high_resolution_clock::now();
        durationRecursive += std::chrono::duration_cast<std::chrono::microseconds>(endRecursive - startRecursive);
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(0ms);
    for (int i = 0; i < cycles; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto output = solutionTwo(input);
        auto end = std::chrono::high_resolution_clock::now();
        duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    cout << "Brute force took: " << duration.count() / cycles << " microseconds.\n";
    cout << "Recursive took: " << durationRecursive.count() / cycles << " microseconds.\n";
}

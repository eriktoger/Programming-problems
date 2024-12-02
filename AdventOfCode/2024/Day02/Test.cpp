#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include "solutionOne.h"
#include "solutionTwo.h"

TEST(PartOne, demo)
{
    auto demoInputPath = partOnePath + "demo-input.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionOne(input);
    auto demoAnswerPath = partOnePath + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partOnePath + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartOne, input)
{
    auto inputPath = partOnePath + "input.txt";
    auto input = fromFileToVector(inputPath);

    auto output = solutionOne(input);
    auto answerPath = partOnePath + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = partOnePath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, demo)
{
    auto demoInputPath = partTwoPath + "demo-input.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionTwo(input);
    auto demoAnswerPath = partTwoPath + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, input)
{
    auto inputPath = partTwoPath + "input.txt";
    auto input = fromFileToVector(inputPath);
    auto start = std::chrono::high_resolution_clock::now();
    auto output = solutionTwo(input);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Brute force took: " << duration.count() << " microseconds.\n";

    auto answerPath = partTwoPath + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = partTwoPath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwoRecursive, demo)
{
    auto demoInputPath = partTwoPath + "demo-input.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionTwoRecursive(input);

    auto demoAnswerPath = partTwoPath + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwoRecursive, input)
{
    auto inputPath = partTwoPath + "input.txt";
    auto input = fromFileToVector(inputPath);

    auto start = std::chrono::high_resolution_clock::now();
    auto output = solutionTwoRecursive(input);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Recursion took: " << duration.count() << " microseconds.\n";

    auto answerPath = partTwoPath + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = partTwoPath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}
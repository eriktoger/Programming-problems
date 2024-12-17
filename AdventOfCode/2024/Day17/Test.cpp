#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
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

TEST(PartOne, demo2)
{
    auto demoInputPath = partOnePath + "demo-input2.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionOne(input);
    auto demoAnswerPath = partOnePath + "demo-answer2.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partOnePath + "demo-output2.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartOne, demo3)
{

    vector<string> input = {"Register A: 10", "Register B: 0", "Register C: 0", "", "Program: 5,0,5,1,5,4"};
    auto output = solutionOne(input);
    vector<string> answer = {"0,1,2"};
    EXPECT_EQ(output, answer);
}

TEST(PartOne, demoManual)
{
    // should set B to 1
    vector<string> input1 = {"Register A: 0", "Register B: 0", "Register C: 9", "", "Program: 2, 6"};
    auto output1 = solutionOne(input1);

    // should set B to 26
    vector<string> input2 = {"Register A: 0", "Register B: 29", "Register C: 0", "", "Program: 1, 7"};
    auto output2 = solutionOne(input2);

    // should set B to 44354
    vector<string> input3 = {"Register A: 0", "Register B: 2024", "Register C: 43690", "", "Program: 4, 0"};
    auto output3 = solutionOne(input3);
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

    auto output = solutionTwo(input);
    auto answerPath = partTwoPath + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = partTwoPath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

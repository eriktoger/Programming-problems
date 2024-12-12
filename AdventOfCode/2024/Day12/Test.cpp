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

TEST(PartTwo, demo2)
{
    auto demoInputPath = partTwoPath + "demo-input2.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionTwo(input);
    auto demoAnswerPath = partTwoPath + "demo-answer2.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output2.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, demo3)
{
    auto demoInputPath = partTwoPath + "demo-input3.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionTwo(input);
    auto demoAnswerPath = partTwoPath + "demo-answer3.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output3.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, demo4)
{
    auto demoInputPath = partTwoPath + "demo-input4.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solutionTwo(input);
    auto demoAnswerPath = partTwoPath + "demo-answer4.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output4.txt";
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

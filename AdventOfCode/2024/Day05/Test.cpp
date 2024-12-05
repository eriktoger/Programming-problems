#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "solutionOne.h"
#include "solutionTwo.h"

TEST(PartOne, demo)
{
    auto demoInputPathA = partOnePath + "demo-inputA.txt";
    auto inputA = fromFileToVector(demoInputPathA);
    auto demoInputPathB = partOnePath + "demo-inputB.txt";
    auto inputB = fromFileToVector(demoInputPathB);

    auto output = solutionOne(inputA, inputB);
    auto demoAnswerPath = partOnePath + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partOnePath + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartOne, input)
{
    auto inputPathA = partOnePath + "inputA.txt";
    auto inputA = fromFileToVector(inputPathA);
    auto inputPathB = partOnePath + "inputB.txt";
    auto inputB = fromFileToVector(inputPathB);

    auto output = solutionOne(inputA, inputB);
    auto demoAnswerPath = partOnePath + "answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto outputPath = partOnePath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, demo)
{
    auto demoInputPathA = partTwoPath + "demo-inputA.txt";
    auto inputA = fromFileToVector(demoInputPathA);
    auto demoInputPathB = partTwoPath + "demo-inputB.txt";
    auto inputB = fromFileToVector(demoInputPathB);

    auto output = solutionTwo(inputA, inputB);
    auto demoAnswerPath = partTwoPath + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = partTwoPath + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, input)
{
    auto inputPathA = partTwoPath + "inputA.txt";
    auto inputA = fromFileToVector(inputPathA);
    auto inputPathB = partTwoPath + "inputB.txt";
    auto inputB = fromFileToVector(inputPathB);

    auto output = solutionTwo(inputA, inputB);
    auto answerPath = partTwoPath + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = partTwoPath + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

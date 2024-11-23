#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "solution.h"

TEST(PartOne, demo)
{
    auto demoInputPath = path + "demo-input.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solution(input);
    auto demoAnswerPath = path + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = path + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartOne, input)
{
    auto inputPath = path + "input.txt";
    auto input = fromFileToVector(inputPath);

    auto output = solution(input);
    auto answerPath = path + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = path + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}

/*
TEST(PartTwo, demo)
{
    auto demoInputPath = path + "demo-input.txt";
    auto input = fromFileToVector(demoInputPath);

    auto output = solution(input);
    auto demoAnswerPath = path + "demo-answer.txt";
    auto answer = fromFileToVector(demoAnswerPath);

    auto demoOutputPath = path + "demo-output.txt";
    fromVectorToFile(demoOutputPath, output);
    EXPECT_EQ(output, answer);
}

TEST(PartTwo, input)
{
    auto inputPath = path + "input.txt";
    auto input = fromFileToVector(inputPath);

    auto output = solution(input);
    auto answerPath = path + "answer.txt";
    auto answer = fromFileToVector(answerPath);

    auto outputPath = path + "output.txt";
    fromVectorToFile(outputPath, output);
    EXPECT_EQ(output, answer);
}
*/

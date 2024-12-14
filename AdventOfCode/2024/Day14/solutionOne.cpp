#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{

    vector<Robot> robots;
    vector<long long> quadrantCounts{0, 0, 0, 0};

    int widthTreshold = width / 2;
    int heightTreshold = height / 2;
    for (const auto &line : input)
    {
        smatch match;
        regex_search(line, match, numbersPattern);
        auto position = Coordinate{stoi(match[1]), stoi(match[2])};
        auto direction = Coordinate{stoi(match[3]), stoi(match[4])};
        auto robot = Robot{position, direction, -1};
        robot.move(100);

        if (robot.position.x < widthTreshold && robot.position.y < heightTreshold)
        {
            quadrantCounts[0]++;
            robot.quadrant = 0;
        }
        else if (robot.position.x < widthTreshold && robot.position.y > heightTreshold)
        {
            quadrantCounts[1]++;
            robot.quadrant = 1;
        }
        else if (robot.position.x > widthTreshold && robot.position.y < heightTreshold)
        {
            quadrantCounts[2]++;
            robot.quadrant = 2;
        }
        else if (robot.position.x > widthTreshold && robot.position.y > heightTreshold)
        {
            quadrantCounts[3]++;
            robot.quadrant = 3;
        }
        else
        {
            robot.quadrant = -1;
        }

        robots.emplace_back(robot);
    }

    long long answer = quadrantCounts[0] * quadrantCounts[1] * quadrantCounts[2] * quadrantCounts[3];

    return {to_string(answer)};
}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> fromFileToVector(string fileName);
void fromVectorToFile(string fileName, vector<string> const &input);
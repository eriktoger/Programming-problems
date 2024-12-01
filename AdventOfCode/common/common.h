#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> fromFileToVector(string fileName);
vector<vector<string>> splitLinesToWords(vector<string> const &input);
void fromVectorToFile(string fileName, vector<string> const &input);

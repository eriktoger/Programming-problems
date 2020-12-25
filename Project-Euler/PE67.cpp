#include "../Other/BigInteger/BigInteger.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
void populatePyramid(vector < vector <int> > &pyramid);
void traversePyramid(vector < vector <int> > &pyramid);

int main() {
    vector < vector <int> > pyramid;
    populatePyramid(pyramid);
    traversePyramid(pyramid);
    cout << pyramid[0][0]<<endl;
}

void populatePyramid(vector < vector <int> > &pyramid){
    ifstream file("Project-Euler/p067_triangle.txt");
    string valueString;

    while (getline(file, valueString)) {
        istringstream  numberStream(valueString);
        string line;
        vector <int> tempVec;
        while(getline(numberStream,line, ' ')){
            tempVec.emplace_back(stoi(line));
        }
        pyramid.emplace_back(tempVec);
    }
}

void traversePyramid(vector < vector <int> > &pyramid){
    int rows = pyramid.size();
    while(rows--){
        auto &row = pyramid[rows];
        for(int i = 0; i< row.size() - 1; i++ ){
            pyramid[rows - 1][i] += row[i] > row[i+1] ? row[i] : row[i+1];
        }
    }
}
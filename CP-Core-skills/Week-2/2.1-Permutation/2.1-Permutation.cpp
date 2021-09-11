#include "2.1-Permutation.h"
#include <vector>
#include <algorithm>

using namespace std;

void func(std::istream &is, std::ostream &os) {
    int size;
    cin >> size;
    vector<vector<int> > matrix;
    int rows = size;
    while (rows--) {
        int columns = size;
        vector<int> row;
        while (columns--) {
            int number;
            cin >> number;
            row.emplace_back(number);
        }
        matrix.emplace_back(row);
    }
    vector<int> numbers(size);
    iota(begin(numbers), end(numbers), 1);

    int minimumCost = 9000;
    vector<int> minimumCostPermutation;

    do {
        int sum = 0;
        for(int i = 0; i < numbers.size() -1 ; i++){
            sum += matrix[numbers[i] -1 ][numbers[i+1] -1];
        }
        if( sum < minimumCost){
            minimumCostPermutation = numbers;
            minimumCost = sum;
        }

    } while (next_permutation(begin(numbers), end(numbers)));

    for( int i= 0; i<minimumCostPermutation.size();i++){
        cout << minimumCostPermutation.at(i);
        if(i != minimumCostPermutation.size()-1 ){
            cout << " ";
        }
    }
}
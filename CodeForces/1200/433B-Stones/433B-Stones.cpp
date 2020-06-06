#include "433B-Stones.h"

void stones(std::istream &is, std::ostream &os) {

    int nrOfStones;
    vector<unsigned long long int> theStones{0};
    cin >> nrOfStones;
    while (nrOfStones--) {
        int stone;
        cin >> stone;
        theStones.emplace_back(stone);
    }
    vector<unsigned long long int> theStonesSorted = theStones;
    sort(theStonesSorted.begin(), theStonesSorted.end());
    int questions;

    unsigned long long int partialSum[theStones.size()];
    unsigned long long int partialSumSorted[theStonesSorted.size()];
    std::partial_sum(theStones.begin(), theStones.end(), partialSum);
    std::partial_sum(theStonesSorted.begin(), theStonesSorted.end(), partialSumSorted);

    cin >> questions;
    while (questions--) {
        int type;
        int idx1;
        int idx2;
        cin >> type;
        cin >> idx1;
        cin >> idx2;
        if (type == 1) {
            cout << partialSum[idx2] - partialSum[idx1-1] <<'\n';
        }else{
            cout << partialSumSorted[idx2] - partialSumSorted[idx1-1] <<'\n';
        }
    }
}
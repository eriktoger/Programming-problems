#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>

using namespace std;

vector<shared_ptr<int> > constructPointers();

vector<vector<shared_ptr<int> > > constructRing(vector<shared_ptr<int> > const &pointers);

void placeNumbers(string const &combinations, vector<shared_ptr<int> > const &pointers);

bool isEqual(vector<vector<shared_ptr<int> > > const &ring);

int startingPoint(vector<vector<shared_ptr<int> > > const &ring);

string concatNumbers(int lowestR, vector<vector<shared_ptr<int> > > const &ring);

int main() {
    auto pointers = constructPointers();
    auto ring = constructRing(pointers);

    string combinations = "abcdefghij";
    string answer;
    do {

        placeNumbers(combinations, pointers);
        bool allEqual = isEqual(ring);

        if (allEqual) {
            int lowestR = startingPoint(ring);
            string concat = concatNumbers(lowestR, ring);

            if (concat.size() == 16 && concat > answer) {
                answer = concat;
            }
        }
    } while (next_permutation(combinations.begin(), combinations.end()));

    cout << "answer: " << answer << endl;
}

vector<shared_ptr<int> > constructPointers() {
    auto a = make_shared<int>();
    auto b = make_shared<int>();
    auto c = make_shared<int>();
    auto d = make_shared<int>();
    auto e = make_shared<int>();
    auto f = make_shared<int>();
    auto g = make_shared<int>();
    auto h = make_shared<int>();
    auto i = make_shared<int>();
    auto j = make_shared<int>();

    return {a, b, c, d, e, f, g, h, i, j};

}

vector<vector<shared_ptr<int> > > constructRing(vector<shared_ptr<int> > const &pointers) {
    return {{pointers[0], pointers[1], pointers[2]},
            {pointers[3], pointers[2], pointers[4]},
            {pointers[5], pointers[4], pointers[6]},
            {pointers[7], pointers[6], pointers[8]},
            {pointers[9], pointers[8], pointers[1]}};

}

void placeNumbers(string const &combinations, vector<shared_ptr<int> > const &pointers) {
    int counter = 1;
    for (auto const &chr : combinations) {
        *pointers[chr - 'a'] = counter;
        counter++;
    }
}

bool isEqual(vector<vector<shared_ptr<int> > > const &ring) {
    for (int r = 0; r < ring.size() - 1; r++) {
        auto lambda = [](const int acc, const shared_ptr<int> &ptr) { return acc + *ptr; };
        if (accumulate(begin(ring[r]), end(ring[r]), 0, lambda) !=
            accumulate(begin(ring[r + 1]), end(ring[r + 1]), 0, lambda)) {
            return false;
        }
    }

    return true;
}

int startingPoint(vector<vector<shared_ptr<int> > > const &ring) {
    int lowestR = 0;
    for (int r = 0; r < ring.size(); r++) {
        if (*ring[r][0] < *ring[lowestR][0]) {
            lowestR = r;
        }
    }
    return lowestR;
}

string concatNumbers(int lowestR, vector<vector<shared_ptr<int> > > const &ring) {
    auto nrOfRows = ring.size();
    string concat;
    while (nrOfRows--) {
        auto index = lowestR % ring.size();
        concat += to_string(*ring[index][0]) + to_string(*ring[index][1]) + to_string(*ring[index][2]);
        lowestR++;
    }
    return concat;
}
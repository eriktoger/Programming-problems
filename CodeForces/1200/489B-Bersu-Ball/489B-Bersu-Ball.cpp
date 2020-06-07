#include "489B-Bersu-Ball.h"


void ball(std::istream &is, std::ostream &os) {
    int boyCount;
    cin >> boyCount;
    vector<int> boys;
    while (boyCount--) {
        int boy;
        cin >> boy;
        boys.emplace_back(boy);
    }
    int girlCount;
    cin >> girlCount;
    vector<int> girls;
    while (girlCount--) {
        int girl;
        cin >> girl;
        girls.emplace_back(girl);
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    auto itBoy = boys.begin();
    auto itGirl = girls.begin();

    int pairs = 0;
    while (itBoy != boys.end() && itGirl != girls.end()) {
        while (itGirl != girls.end()) {
            if (abs(*itBoy - *itGirl) <= 1) {
                pairs++;
                itBoy++;
                itGirl++;
                break;
            } else if (*itBoy > *itGirl) {
                itGirl++;
            } else if (*itGirl > *itBoy) {
                itBoy++;
            }
        }
    }

    cout << pairs;


}
#include "1.1-A-a-S.h"

void func(std::istream &is, std::ostream &os) {
    int x;
    int y;
    int target;
    cin >> x;
    cin >> y;
    cin >> target;
    int counter = 0;
    int current = 0;
    //we will not go anywhere if x == y;
    if( x == y){
        if(target == 0){
            cout << 0;
            return;
        }
        if(target == x){
            cout << 1;
            return;
        }
        cout << -1;
        return;
    }
    while (current != target) {
        counter++;
        if (counter % 2 == 0) {
            current -= y;
            if( target > 0 && current > target){
                cout << -1;
                return;
            }
        } else {
            current += x;
            if(target < 0 && current < target){
                cout << -1;
                return;
            }
        }

    }
    cout << counter;
}
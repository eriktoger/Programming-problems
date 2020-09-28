#include "520B-Two-Buttons.h"

void func(std::istream &is, std::ostream &os) {
    int start;
    int stop;
    cin >> start;
    cin >> stop;
    int pushes = 0;

    while(start != stop){

        if(stop % 2 ==0 && stop > start){
            stop /=2;
        }else{
            stop++;
        }
        pushes++;
    }

    cout << pushes;

}
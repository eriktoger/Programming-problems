#include <iostream>
//https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
void watermelon () {
    int w;
    std::cin >> w;
    if (w%2 == 0 && w > 2){
        std::cout <<"YES";
    }
    else{
        std::cout <<"NO";
    }
}
#include "4A-WaterMelon.h"

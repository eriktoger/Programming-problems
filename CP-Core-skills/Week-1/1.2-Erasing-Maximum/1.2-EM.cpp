#include "1.2-EM.h"

void func(std::istream &is, std::ostream &os) {
    int n;
    cin >> n;
    vector<int> numbers;
    numbers.reserve(n);
    int counter = 0;
    int max = 0;
    int it = 0;
    int itCounter = 0;
    while(n--){
        int temp;
        cin >> temp;
        if(temp > max){
            max = temp;
            counter = 1;
            it = itCounter;
        } else if(temp == max){
            counter++;
            if(counter == 3){
               it = itCounter;
            }
        }
        itCounter++;
        numbers.emplace_back(temp);
    }
    numbers.erase(numbers.begin()+it);
    for(auto &num : numbers){
        cout << num << " ";
    }
}
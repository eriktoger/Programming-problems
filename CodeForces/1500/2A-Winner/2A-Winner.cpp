#include "2A-Winner.h"
void func(std::istream &is, std::ostream &os) {

    int rounds;
    cin >> rounds;
    int counter = 1;
    map<string,Person> persons;
    string name;
    int value;
    while(rounds--){
        cin >> name;
        cin >> value;
        if ( persons.count(name) ) {

            persons[name].changeScore(value,counter);
        }else{
            persons[name] = Person();
            persons[name].changeScore(value,counter);
        }

        counter++;
    }

    auto maxPerson = persons.begin();
    auto it = persons.begin();
    while(it != persons.end()){
        if( maxPerson->second < it->second ){
            maxPerson = it;
        }
        it++;
    }
    cout << maxPerson->first;

}
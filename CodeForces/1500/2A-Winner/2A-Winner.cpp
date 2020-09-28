#include "2A-Winner.h"

void func(std::istream &is, std::ostream &os) {

    int rounds;
    cin >> rounds;
    int counter = 1;
    map<string, Person> persons;
    string name;
    int value;
    while (rounds--) {
        cin >> name;
        cin >> value;
        if (persons.count(name)) {

            persons[name].changeScore(value, counter);
        } else {
            persons[name] = Person();
            persons[name].changeScore(value, counter);
        }

        counter++;
    }

    cout << max_element(persons.begin(), persons.end(), [](auto it1, auto it2) {
        return it1.second < it2.second;
    })->first;

}
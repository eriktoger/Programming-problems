#include "4C-Registration.h"


void func(std::istream &is, std::ostream &os) {
    int nrOfNames;
    cin >> nrOfNames;
    map<string, int> occurrences;
    vector<string> names;

    string name;
    while (nrOfNames--) {
        cin >> name;
        if (occurrences.count(name)) {
            occurrences[name]++;
            names.emplace_back(name + to_string(occurrences[name]));
        } else {
            occurrences[name];
            names.emplace_back("OK");
        }
    }

    for (auto const &name:names) {
        cout << name<<endl;
    }

}
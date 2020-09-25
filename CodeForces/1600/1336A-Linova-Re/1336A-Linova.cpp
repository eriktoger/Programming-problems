#include "1336A-Linova.h"
//maybe write it as using objects instead of pointers?
// have everything in vector ( and use index as instant access)
// start with City(0) which has very low score (ore remove it before sorting)
// and see if it helps.

void City::traverse(int from, int newDepth, vector<City> &cities,vector <int> visited) {

    //rewrite without recursion?

    visited.emplace_back(id);
    if (leadsTo.size() == 1 && id != 1) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = i + 1; j < visited.size(); j++) {
                cities[visited[i]].children.insert(visited[j]);
            }
        }
    }

    for (auto const &city_id: leadsTo) {
        if (city_id != from) {
            cities[city_id].last = from;
            cities[city_id].setDepth(newDepth);
            cities[city_id].traverse(id, newDepth + 1, cities, visited);
        }
    }
}


bool compare(City const &c1, City const &c2) {
    return c1.getScore() < c2.getScore();
}

void func(std::istream &is, std::ostream &os) {

    int nrOfCities;
    int nrOfIndustries;
    cin >> nrOfCities;
    cin >> nrOfIndustries;
    int roads = nrOfCities -1;
    map<int, shared_ptr<City> > cities;

    if (nrOfCities == nrOfIndustries) {
        cout << "0";
        return;
    }
    if (nrOfCities - nrOfIndustries == 1) {
        cout << nrOfIndustries;
        return;
    }
    //read
    while (roads--) {
        int id1, id2;
        cin >> id1;
        cin >> id2;

        cities[id1].setID(id1);
        cities[id2].setID(id2);
        cities[id1].addCity(id2);
        cities[id2].addCity(id1);

    }

    int startingDepth = 1;
    int startingCity = 1;
    vector<int> visited;
    cities.at(1).traverse(startingCity, startingDepth, cities, visited);

    for (auto &city: cities) {
        if (city.isLeaf()) {
            //city.calcChildren(cities);
        }
    }

    long long sum = 0;
    cities.erase(cities.begin()); // remove fake zero index City
    sort(cities.begin(), cities.end(), compare);
    auto index = cities.size() - 1;
    while (nrOfIndustries--) {
        sum += cities[index].getScore();
        index--;
    }

    cout << sum;

}
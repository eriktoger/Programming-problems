#include "1336A-Linova.h"
//maybe write it as using objects instead of pointers?
// have everything in vector ( and use index as instant access)
// start with City(0) which has very low score (ore remove it before sorting)
// and see if it helps.
City::City(int _id) {
    id = _id;
    score = 0;
    depth = 0;
    leaf = false;
}

void City::traverse(int from, int newDepth, map<int, shared_ptr<City>> &cities) {

    for (auto const &city_id: leadsTo) {
        if (city_id != from) {
            cities.at(city_id)->setScore(newDepth);
            cities.at(city_id)->setDepth(newDepth);
            cities.at(city_id)->traverse(id, newDepth + 1, cities);
        }
    }
}

void addingCity(int id1, int id2, map<int, shared_ptr<City> > &cities) {
    if (!cities.count(id1)) {
        auto city1 = make_shared<City>(id1);
        city1->addCity(id2);
        cities.insert({id1, city1});
    } else {
        cities.at(id1)->addCity(id2);
    }
}

void City::penalty(map<int, shared_ptr<City>> &cities) {
    // you are losing points equal to cities on the branch below you
    vector<int> log{ leadsTo };

    int index = 0;
    while (index < log.size()) {
        auto num = log[index];
        auto city = cities.at(num);
        city->setScore(city->getScore()  + city->getDepth() - depth);

        for (auto c: city->leadsTo) {
            if (cities.at(c)->getDepth() < city->depth) {
                log.emplace_back(c);
            }
        }
        index++;
    }
}

bool compare(shared_ptr<City> const &c1, shared_ptr<City> const &c2) {
    return c1->getScore() < c2->getScore();
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

        addingCity(id1, id2, cities);
        addingCity(id2, id1, cities);
    }

    int startingDepth = 1;
    int startingCity = 1;
    cities.at(1)->setDepth(startingDepth);
    cities.at(1)->traverse(startingCity, startingDepth, cities);

    vector<shared_ptr<City> > cityVec; // use reserve? https://www.walletfox.com/course/darkercornerscpp_vecreservespace.php
    cityVec.reserve(nrOfCities);
    for (auto &city: cities) {
        city.second->calcIsLeaf();
        if(city.second->isLeaf()){
            city.second->penalty(cities);
        }

        cityVec.emplace_back(city.second);
    }


    int sum = 0;
    sort(cityVec.begin(), cityVec.end(), compare);
    auto index = cityVec.size() -1;
    while (nrOfIndustries--){
        sum += cityVec[index]->getScore();
        index--;
    }

    cout << sum;

}

#include "main.h"
int CAPITAL_INDEX = 0;

void func(std::istream &is, std::ostream &os)
{
    int nrOfCities;
    int nrOfFactories;
    cin >> nrOfCities;
    cin >> nrOfFactories;
    int nrOfRoads = nrOfCities - 1;
    vector<City> cities_array(nrOfCities);
    map<int, vector<int>> unsorted_roads;

    readRoads(nrOfRoads, unsorted_roads);

    generateCities(unsorted_roads, cities_array);

    sort(cities_array.begin(), cities_array.end(), greater<City>());

    long long int happiness = accumulate(cities_array.begin(), cities_array.begin() + nrOfFactories, 0LL);

    cout << happiness;
}

void readRoads(int nrOfRoads, map<int, vector<int>> &unsorted_roads)
{
    while (nrOfRoads--)
    {
        int city1;
        int city2;

        cin >> city1;
        cin >> city2;

        unsorted_roads[city1 - 1].push_back(city2 - 1);
        unsorted_roads[city2 - 1].push_back(city1 - 1);
    }
}

vector<int> orderLeafs(const map<int, vector<int>> &leafsMap)
{
    vector<int> leafsVector;
    for (int i = leafsMap.size(); i > 0; i--)
    {
        auto leafs = leafsMap.at(i);
        {
            for (auto leaf : leafs)
            {
                leafsVector.emplace_back(leaf);
            }
        }
    }
    return leafsVector;
}

void updateDescendants(vector<int> &leafsVector, vector<City> &cities_array)
{
    unsigned index = 0;
    while (index < leafsVector.size())
    {

        auto &currentCity = cities_array[leafsVector[index]];
        auto &parentCity = cities_array[currentCity.parent];
        parentCity.descendants += currentCity.descendants + 1;

        index++;
    }
}

void generateCities(map<int, vector<int>> &unsorted_roads, vector<City> &cities_array)
{

    vector<int> unvisited{0};
    unsigned index = 0;
    map<int, bool> visitied;
    map<int, vector<int>> leafsMap;
    while (index < unvisited.size())
    {
        int parent = unvisited[index];

        if (parent != CAPITAL_INDEX)
        {
            leafsMap[cities_array[parent].distance].emplace_back(parent);
        }

        for (auto road : unsorted_roads.at(parent))
        {
            if (road != parent && visitied.count(road) == 0)
            {
                cities_array[road] = City(parent, cities_array[parent].distance + 1);
                cities_array[parent].children.push_back(road);
                unvisited.push_back(road);
            }
        }

        visitied[parent] = true;
        index++;
    }

    vector<int> leafsVector = orderLeafs(leafsMap);

    updateDescendants(leafsVector, cities_array);
}

long long operator+(long long i, const City &c)
{
    return i + c.calcHappiness();
}
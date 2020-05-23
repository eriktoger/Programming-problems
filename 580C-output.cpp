#include <vector>
#include <map>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void kefaAndPark(std::istream &is = cin, std::ostream &os = cout);

void
readData(vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit, std::istream &is = cin);

void dfs(int node, int parent, vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit, int &restaurants);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    kefaAndPark();
    return 0;
}


void kefaAndPark(std::istream &is, std::ostream &os) {

    vector<int> catsInNode;
    int catLimit;

    map<int, vector<int> > adjacencyList;
    readData(catsInNode, adjacencyList, catLimit, is);
    int restaurants = 0;
    dfs(1, 0, catsInNode, adjacencyList, catLimit, restaurants);

    cout << restaurants;
}


void
readData(vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit,
         std::istream &is) {
    int nrOfNodes;
    is >> nrOfNodes;
    int nrOfEdges = nrOfNodes - 1;
    is >> catLimit;
    while (nrOfNodes--) {
        int cat;
        is >> cat;
        catsInNode.emplace_back(cat);
    }
    while (nrOfEdges--) {
        int node1;
        int node2;
        is >> node1;
        is >> node2;

        adjacencyList[min(node1, node2)].emplace_back(max(node1, node2));
        adjacencyList[max(node1, node2)].emplace_back(min(node1, node2));

    }
}

void dfs(int node, int parent, vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit,
         int &restaurants) {
    vector<int> children = adjacencyList[node];
    children.erase(remove(children.begin(), children.end(), parent), children.end());
    if (children.empty()) {
        if (catsInNode[node - 1] <= catLimit) {
            restaurants++;
        }
    } else {
        for (int child : children) {
            catsInNode[child - 1] = (catsInNode[node - 1] + catsInNode[child - 1]) * catsInNode[child - 1];
            if(catsInNode[child-1] <= catLimit){
                dfs(child, node, catsInNode, adjacencyList, catLimit, restaurants);
            }
        }
    }

}
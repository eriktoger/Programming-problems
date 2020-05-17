#define CATCH_CONFIG_MAIN

#include "Determining-DNA-Health.h"
#include "Aho-Corasick.h"
#include "../../../catch.hpp"

void func() {
    string input;
    cin >> input;
    cout << input;
}

//we have 3 different algorithms
// when strands are long orignal or Aho os prefered?
// when strands are shot reverse are prefered?


TEST_CASE("Sample case from file", "Template") {
    vector<strandInfo> strands;
    vector<string> genes;
    unordered_map<string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/simpleInput.txt";
    readDataFromFile(genesAndHealth, genes, strands, longestGene, path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;
    unsigned long gAh = genesAndHealth.size();

    for (strandInfo &strand : strands) {
        if (strand.strand.length() < 20 || gAh > 1000) {
            calcHealth(genesAndHealth, strand, maxNr, minNr, longestGene);
        } else {
            calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
        }
    }

    REQUIRE(minNr == 0);
    REQUIRE(maxNr == 19);
    cout <<"sample done" <<endl;

}


TEST_CASE("Testcase 10 from file", "Template") {
    vector<strandInfo> strands;
    vector<string> genes;
    unordered_map<string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/testcase10.txt";
    readDataFromFile(genesAndHealth, genes, strands, longestGene, path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;

    for (strandInfo &strand : strands) {
        calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
    }

    REQUIRE(minNr == 0);
    REQUIRE(maxNr == 292498482);
    cout <<"Testcase 10 done" <<endl;

}

TEST_CASE("Testcase 13 from file", "Template") {
    vector<strandInfo> strands;
    vector<string> genes;
    unordered_map<string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/testcase13.txt";
    readDataFromFile(genesAndHealth, genes, strands, longestGene, path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;

    for (strandInfo &strand : strands) {
        calcHealth(genesAndHealth, strand, maxNr, minNr, longestGene);
    }

    REQUIRE(minNr == 40124729287);
    REQUIRE(maxNr == 61265329670);

    cout <<"Testcase 13 done" <<endl;

}

TEST_CASE("Testcase 31 from file", "Template") {

    vector<strandInfo> strands;
    vector<string> genes;
    unordered_map<string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/testcase31.txt";
    readDataFromFile(genesAndHealth, genes, strands, longestGene, path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;
    unsigned long gAh = genesAndHealth.size();

    for (strandInfo &strand : strands) {
        if (strand.strand.length() < 20 || gAh > 1000) {
            calcHealth(genesAndHealth, strand, maxNr, minNr, longestGene);
        } else {
            calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
        }
    }

    REQUIRE(minNr == 1823728075410);
    REQUIRE(maxNr == 1823728075410);

    cout <<"Testcase 31 done" <<endl;

}

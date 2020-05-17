#define CATCH_CONFIG_MAIN
#include "Determining-DNA-Health.h"
#include "../../../catch.hpp"

void func() {
    string input;
    cin >> input;
    cout << input;
}

TEST_CASE( "Sample case from file", "Template" ) {
    vector <strandInfo> strands;


    unordered_map <string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/simpleInput.txt";
    readDataFromFile(genesAndHealth, strands, longestGene,path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;
    unsigned long gAh = genesAndHealth.size();

    for (strandInfo &strand : strands) {
        if(strand.strand.length() < 20 || gAh > 1000){
            calcHealth(genesAndHealth, strand, maxNr, minNr, longestGene);
        }else{
            calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
        }
    }

    REQUIRE(minNr == 0);
    REQUIRE(maxNr == 19);

}


TEST_CASE( "Testcase 10 from file", "Template" ) {
    vector <strandInfo> strands;
    unordered_map <string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    string path = "HackerRank/Hard/Determining-DNA-Health/testcase10.txt";
    readDataFromFile(genesAndHealth, strands, longestGene,path);

    unsigned long long int maxNr = 0;
    unsigned long long int minNr = ULONG_LONG_MAX;

    for (strandInfo &strand : strands) {
        calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
    }

    REQUIRE(minNr == 0);
    REQUIRE(maxNr == 292498482);

}

TEST_CASE( "Testcase 31 from file", "Template" ) {
vector <strandInfo> strands;


       unordered_map <string, vector<healthAndIndex>> genesAndHealth;
       int longestGene = 0;
       string path = "HackerRank/Hard/Determining-DNA-Health/testcase31.txt";
       readDataFromFile(genesAndHealth, strands, longestGene,path);

       unsigned long long int maxNr = 0;
       unsigned long long int minNr = ULONG_LONG_MAX;
       unsigned long gAh = genesAndHealth.size();

       for (strandInfo &strand : strands) {
           if(strand.strand.length() < 20 || gAh > 1000){
               calcHealth(genesAndHealth, strand, maxNr, minNr, longestGene);
           }else{
               calcHealthReverse(genesAndHealth, strand, maxNr, minNr, longestGene);
           }
       }

    REQUIRE(minNr == 1823728075410);
    REQUIRE(maxNr == 1823728075410);

}

#include "Determining-DNA-Health.h"

// I ended up solving it without aho or kmp
// But you really should use some a algorithm like aho or kmp.

void dna() {
    vector <strandInfo> strands;
    unordered_map <string, vector<healthAndIndex>> genesAndHealth;
    int longestGene = 0;
    readData(genesAndHealth, strands, longestGene);

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

    cout << minNr << " " << maxNr;

}

void readData(unordered_map <string, vector<healthAndIndex>> &genesAndHealth, vector <strandInfo> &strands,
              int &longestGene) {
    int n;
    cin >> n;

    vector <string> genes;
    int nrOfGenes = n;
    while (nrOfGenes--) {
        string gene;
        cin >> gene;
        longestGene = max(longestGene, (int) gene.length());
        genes.emplace_back(gene);
    }

    vector<int> healths;
    int nrOfHealths = n;
    while (nrOfHealths--) {
        int health;
        cin >> health;
        healths.emplace_back(health);
    }

    int s;
    cin >> s;

    int nrOfStrands = s;
    unsigned long longestStrand = 0;
    while (nrOfStrands--) {
        int first;
        int second;
        string strand;
        cin >> first;
        cin >> second;
        cin >> strand;
        longestStrand = max(longestStrand, strand.length());
        strands.emplace_back(strandInfo{first, second, strand});
    }


    for (int i = 0; i < n; i++) {
        if (genes[i].length() <= longestStrand) {
            if (genesAndHealth.find(genes[i]) == genesAndHealth.end()) {
                vector <healthAndIndex> hi{healthAndIndex{healths[i], i}};
                genesAndHealth[genes[i]] = hi;
            } else {
                genesAndHealth[genes[i]].emplace_back(healthAndIndex{healths[i], i});
            }
        }
    }
}

void
calcHealth(unordered_map <string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
           unsigned long long int &maxNr, unsigned long long int &minNr,
           int &longestGene) {

    unsigned long long int sum = 0;

    for (int i = 1; i <= longestGene && i <= strand.strand.length(); i++) {
        for (int j = 0; j <= (strand.strand.length() - i); j++) {
            string subString = strand.strand.substr(j, i);
            if (genesAndHealth.find(subString) != genesAndHealth.end()) {
                for (auto hi :genesAndHealth[subString]) {
                    if (hi.idx >= strand.start && hi.idx <= strand.end) {
                        sum += hi.health;
                    }
                }
            }
        }
    }

    maxNr = max(maxNr, sum);
    minNr = min(minNr, sum);

}

void
calcHealthReverse(unordered_map <string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
                  unsigned long long int &maxNr, unsigned long long int &minNr,
                  int &longestGene) {

    unsigned long long int sum = 0;
    int strandLength = strand.strand.length();
    for (auto &gAh: genesAndHealth) {
        for (auto hi : gAh.second) {
            if (hi.idx >= strand.start && hi.idx <= strand.end && gAh.first.length() < 16) {
                int offset = 0;
                while (true) {
                    auto it = search(strand.strand.begin() + offset, strand.strand.end(),
                                     (gAh.first).begin(), (gAh.first).end());
                    if (it != strand.strand.end()) {
                        sum += hi.health;
                        offset = it - strand.strand.begin() + 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    maxNr = max(maxNr, sum);
    minNr = min(minNr, sum);

}

void readDataFromFile(unordered_map <string, vector<healthAndIndex>> &genesAndHealth, vector <string> &genes,vector <strandInfo> &strands,
                      int &longestGene, string &path) {
    ifstream inFile;
    inFile.open(path);
    if (!inFile) {
        return;
    }
    int n;
    inFile >> n;

    int nrOfGenes = n;
    while (nrOfGenes--) {
        string gene;
        inFile >> gene;
        longestGene = max(longestGene, (int) gene.length());
        genes.emplace_back(gene);
    }

    vector<int> healths;
    int nrOfHealths = n;
    while (nrOfHealths--) {
        int health;
        inFile >> health;
        healths.emplace_back(health);
    }

    int s;
    inFile >> s;

    int nrOfStrands = s;
    unsigned long longestStrand = 0;
    while (nrOfStrands--) {
        int first;
        int second;
        string strand;
        inFile >> first;
        inFile >> second;
        inFile >> strand;
        longestStrand = max(longestStrand, strand.length());
        strands.emplace_back(strandInfo{first, second, strand});
    }


    for (int i = 0; i < n; i++) {
        if (genes[i].length() <= longestStrand) {
            if (genesAndHealth.find(genes[i]) == genesAndHealth.end()) {
                vector <healthAndIndex> hi{healthAndIndex{healths[i], i}};
                genesAndHealth[genes[i]] = hi;
            } else {
                genesAndHealth[genes[i]].emplace_back(healthAndIndex{healths[i], i});
            }
        }
    }

}

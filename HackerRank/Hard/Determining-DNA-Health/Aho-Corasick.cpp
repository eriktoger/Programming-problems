#include "Aho-Corasick.h"

void AhoCorasick(unordered_map<string, vector<healthAndIndex> > &genesAndHealth, vector<string> &genes, vector <strandInfo> &strands,unsigned long long int &maxStrand, unsigned long long int &minStrand){

    ac_automaton automaton(begin(genes), end(genes));


    for(const auto &strand : strands){

        std::vector<std::pair<std::string, int> > results;
        automaton.search(strand.strand, std::back_inserter(results));
        unsigned long long sum = 0;
        for (auto &result : results) {
            vector<healthAndIndex> targets = genesAndHealth[result.first];
            for (auto target : targets) {
                if (target.idx >= strand.start && target.idx <= strand.end) {
                    sum += target.health;
                }
            }
        }
        minStrand = min(minStrand, sum);
        maxStrand = max(maxStrand, sum);
    }

}
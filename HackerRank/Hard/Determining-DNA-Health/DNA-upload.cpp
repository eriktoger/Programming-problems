#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

static constexpr int MAXCHARS = 26;

struct healthAndIndex {
    int health;
    int idx;
};
struct strandInfo {
    int start;
    int end;
    string strand;
};

struct state {
    std::set<int> output_function;
    int failure_function;
    std::vector<int> goto_function;

    state()
            : failure_function(-1),
              goto_function(MAXCHARS, -1) {
    }
};

class ac_automaton {
public:
    template<class InputIt>
    ac_automaton(InputIt first, InputIt last)
            : states(1) {
        // Build the prefix tree
        for (InputIt it = first; it != last; ++it) {
            add_word(*it);
        }
        // Turn it into an automaton
        construct_automaton();
    }

    template<class OutputIt>
    OutputIt search(std::string text, OutputIt it) const {
        int current_state = 0;

        for (int i = 0; i < text.size(); ++i) {
            current_state = find_next_state(current_state, text[i]);
            if (states[current_state].output_function.size()) {
                for (auto length : states[current_state].output_function) {
                    *it++ = std::make_pair(std::string(text, i - length + 1, length),
                                           i - length + 1);
                }
            }
        }
        return it;
    }

private:
    std::vector<state> states;

private:
    void add_word(const std::string &word) {
        int current_state = 0;
        // Add to prefix tree
        for (int c : word) {
            int chr = c - 'a';
            if (states[current_state].goto_function[chr] == -1) {
                states[current_state].goto_function[chr] = states.size();
                states.push_back(state());
            }
            current_state = states[current_state].goto_function[chr];
        }
        // Add to output function for this state
        states[current_state].output_function.insert(word.size());
    }

    void construct_automaton() {
        // Complete the goto function by setting it to 0 for each
        // letter that doesn't have an edge from the root
        for (int c = 0; c < MAXCHARS; ++c) {
            if (states[0].goto_function[c] == -1) {
                states[0].goto_function[c] = 0;
            }
        }

        // Compute failure and output functions
        std::queue<int> state_queue;
        for (int c = 0; c < MAXCHARS; ++c) {
            if (states[0].goto_function[c] != 0) {
                states[states[0].goto_function[c]].failure_function = 0;
                state_queue.push(states[0].goto_function[c]);
            }
        }
        while (state_queue.size()) {
            int s = state_queue.front();
            state_queue.pop();

            for (int c = 0; c < MAXCHARS; ++c) {
                if (states[s].goto_function[c] != -1) {
                    int failure = states[s].failure_function;
                    while (states[failure].goto_function[c] == -1) {
                        failure = states[failure].failure_function;
                    }
                    failure = states[failure].goto_function[c];
                    states[states[s].goto_function[c]].failure_function = failure;
                    for (auto length : states[failure].output_function) {
                        states[states[s].goto_function[c]].output_function.insert(length);
                    }
                    state_queue.push(states[s].goto_function[c]);
                }
            }
        }
    }

    int find_next_state(int current_state, char c) const {
        int next_state = current_state;
        int chr = c - 'a';
        while (states[next_state].goto_function[chr] == -1) {
            next_state = states[next_state].failure_function;
        }

        return states[next_state].goto_function[chr];
    }

};

void readData(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, vector<string> &genes,
              vector<strandInfo> &strands,
              int &longestStrand, int &longestGene);

void AhoCorasick(unordered_map<string, vector<healthAndIndex> > &genesAndHealth, vector<string> &genes,
                 vector<strandInfo> &strands, unsigned long long int &maxStrand, unsigned long long int &minStrand);

void calcHealth(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
                unsigned long long int &maxNr, unsigned long long int &minNr,
                int &longestGene);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<strandInfo> strands;
    vector<string> genes;
    unordered_map<string, vector<healthAndIndex>> genesAndHealth;
    int longestStrand = 0;
    int longestGene = 0;
    readData(genesAndHealth, genes, strands, longestStrand, longestGene);

    unsigned long long int maxStrand = 0;
    unsigned long long int minStrand = ULONG_LONG_MAX;

    if (longestStrand <= 10) {
        for (auto strand : strands) {
            calcHealth(genesAndHealth, strand, maxStrand, minStrand, longestGene);
        }
    } else {
        AhoCorasick(genesAndHealth, genes, strands, maxStrand, minStrand);
    }

    cout << minStrand << " " << maxStrand << endl;

    return 0;
}

void readData(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, vector<string> &genes,
              vector<strandInfo> &strands,
              int &longestStrand, int &longestGene) {

    int n;
    cin >> n;

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

    while (nrOfStrands--) {
        int first;
        int second;
        string strand;
        cin >> first;
        cin >> second;
        cin >> strand;
        longestStrand = max(longestStrand, (int) strand.length());
        strands.emplace_back(strandInfo{first, second, strand});
    }


    for (int i = 0; i < n; i++) {
        if (genes[i].length() <= longestStrand) {
            if (genesAndHealth.find(genes[i]) == genesAndHealth.end()) {
                vector<healthAndIndex> hi{healthAndIndex{healths[i], i}};
                genesAndHealth[genes[i]] = hi;
            } else {
                genesAndHealth[genes[i]].emplace_back(healthAndIndex{healths[i], i});
            }
        }
    }

}

void
calcHealth(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
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

void AhoCorasick(unordered_map<string, vector<healthAndIndex> > &genesAndHealth, vector<string> &genes,
                 vector<strandInfo> &strands, unsigned long long int &maxStrand, unsigned long long int &minStrand) {

    ac_automaton automaton(begin(genes), end(genes));

    for (const auto &strand : strands) {

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

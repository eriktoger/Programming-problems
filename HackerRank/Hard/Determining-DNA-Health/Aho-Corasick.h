
//http://www.martinbroadhurst.com/aho-corasick-algorithm-in-c.html
#ifndef AHO_CORASICK_HPP
#define AHO_CORASICK_HPP

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include "Determining-DNA-Health.h"
using namespace std;


void readFromFile(string path, unsigned long long &maxStrand, unsigned long long &minStrand);
void AhoCorasick(unordered_map<string, vector<healthAndIndex> > &genesAndHealth, vector<string> &genes, vector <strandInfo> &strands,unsigned long long int &maxStrand, unsigned long long int &minStrand);


// Maximum number of characters in alphabet
static constexpr int MAXCHARS = 26;

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

#endif // AHO_CORASICK_HPP
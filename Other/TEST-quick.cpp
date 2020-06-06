#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "quick-sort.h"

using namespace std;


TEST_CASE("Example 1", "Template") {
string word = "afdsflse";
cout << word << endl;
quickSort(word,0,word.size()-1);
cout << word <<endl;
}
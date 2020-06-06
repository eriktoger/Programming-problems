
#include <string>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_QUICK_SORT_H
#define COMPETITIVE_PROGRAMMING_QUICK_SORT_H

void quickSort(string &word, int low, int high);

int partition(string &word, int low, int high);

void swap(char *a, char *b);

#endif //COMPETITIVE_PROGRAMMING_QUICK_SORT_H

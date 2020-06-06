#include "quick-sort.h"

void quickSort(string &word, int low, int high) {
    if (low < high) {
        int part = partition(word, low, high);

        quickSort(word, low, part - 1);
        quickSort(word, part + 1, high);
    }
}

int partition(string &word, int low, int high) {
    for (int j = low; j < high; j++) {

        if (word[j] < word[high]) {
            swap(&word[low], &word[j]);
            low++;
        }
    }

    swap(&word[low], &word[high]);
    return low;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
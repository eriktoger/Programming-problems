#include "2.3-Minimums.h"
#include <algorithm>
#include <vector>
using namespace std;

void func(std::istream &is, std::ostream &os) {
  int totalNumbers;
  vector<int> numbers;
  cin >> totalNumbers;
  while (totalNumbers--) {
    int num;
    cin >> num;
    numbers.emplace_back(num);
  }
  totalNumbers = numbers.size();
  long long int answer = 0;
  for (int i = 0; i < totalNumbers; i++) {
    int minimum = 9999999;
    for (int j = i; j < totalNumbers; j++) {
      minimum = min(minimum, numbers[j]);
      answer += minimum;
    }
  }
  cout << answer;
}

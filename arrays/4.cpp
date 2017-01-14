#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalPerm (string str) {
    vector<int> freq = vector<int>(256, 0);
    int i;
    for (i = 0; i < str.size(); i++) freq[(int)str[i]] += 1;
    int sum = 0, cmp = str.size() % 2 == 0 ? 0 : 1;
    for (i = 0; i < 256; i++) sum += freq[i] % 2;
    return sum <= cmp;
}

int main() {
  string str = "abcdbfac";
  cout << (isPalPerm(str) ? "YES" : "NO") << endl;
  return 0;
}

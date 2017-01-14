#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int ALPH_SIZE = 26;

bool isUnique(string str) {
  bool c[ALPH_SIZE] = { false };
  for (int i = 0; i < str.size(); i++) {
    int ind = (int)str[i] - 97;
    if (c[ind]) return false;
    c[ind] = true;
  }
  return true;
}

int main() {
  string test = "abcde";
  cout << (isUnique(test) ? "YES" : "NO") << endl;
  return 0;
}

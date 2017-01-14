#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int ALPH_SIZE = 256;

bool isPerm (string a, string b) {
  vector<int> freq = vector<int>(ALPH_SIZE, 0);
  int i;
  for (i = 0; i < a.size(); i++) freq[(int)a[i]] += 1;
  for (i = 0; i < b.size(); i++) freq[(int)b[i]] -= 1;
  for (i = 0; i < ALPH_SIZE; i++) {
    if (freq[i] != 0) return false;
  }
  return true;
}

int main() {
  string a = "abcde";
  string b = "bdeca";
  cout << (isPerm(a, b) ? "YES" : "NO") << endl;
  return 0;
}

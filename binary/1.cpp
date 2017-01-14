#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include <list>
using namespace std;

void printBinary(int n) {
  string s;
  int c = 64;
  while (n && c-- > 0) {
    s += to_string(n & 1);
    n >>= 1;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}

int insertion(int n, int m, int i, int j) {
  int mask = (~0 << (j + 1)) | ((1 << i) - 1);
  return (mask & n) | (m << i);
}

int main() {
  int n = 1024, m = 19;
  printBinary(n);
  printBinary(m);
  printBinary(insertion(n, m, 2, 6));
  return 0;
}

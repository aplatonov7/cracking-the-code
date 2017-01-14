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

int pairSwap(int a) {
  return ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);
}

int main() {
  int a = 29;
  printBinary(a);
  printBinary(pairSwap(a));
  return 0;
}

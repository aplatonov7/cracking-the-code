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

int bitDiff(int a, int b) {
  int diff = 0;
  for (int c = a ^ b; c != 0; c = c & (c - 1))
    diff += 1;
  return diff;
}

int main() {
  int a = 29;
  int b = 15;
  printBinary(a);
  printBinary(b);
  cout << bitDiff(a, b);
  return 0;
}

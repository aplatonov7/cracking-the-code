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

void printBinary(double n) {
  if (n >= 1 || n <= 0) return;
  string s = ".";
  while (n > 0) {
    if (s.size() > 33) return;
    n *= 2;
    if (n >= 1) {
      s += "1";
      n -= 1;
    } else {
      s += "0";
    }
  }
  cout << s << endl;
}

int main() {
  double n = 0.2578125;
  printBinary(n);
  return 0;
}

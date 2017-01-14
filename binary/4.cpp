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

int getNext(int n) {
  int c = n;
  int c0 = 0;
  int c1 = 0;
  while (((c & 1) == 0) && (c != 0)) {
    c0 += 1;
    c >>= 1;
  }

  while ((c & 1) == 1) {
    c1 += 1;
    c >>= 1;
  }

  if (c0 + c1 == 31 || c0 + c1 == 0) return -1;
  int p = c0 + c1;
  n |= (1 << p);
  n &= ~((1 << p) - 1);
  n |= (1 << (c1 - 1)) - 1;
  return n;
}

int getPrev(int n) {
  int c = n;
  int c0 = 0;
  int c1 = 0;
  while (((c & 1) == 1) && (c != 0)) {
    c1 += 1;
    c >>= 1;
  }

  while ((c & 1) == 0) {
    c0 += 1;
    c >>= 1;
  }

  if (c0 + c1 == 31 || c0 + c1 == 0) return -1;
  int p = c0 + c1;
  n &= ~((1 << p + 1) - 1);
  n |= ((1 << c1 + 1) - 1) << c0 - 1;
  return n;
}

int main() {
  printBinary(getNext(13948));
  printBinary(getPrev(10115));
  return 0;
}

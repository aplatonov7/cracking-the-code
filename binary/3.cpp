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

int flipDaBeat(int n) {
  int res = 1;
  int curlen = 0;
  int prevlen = 0;
  while (n > 0) {
    int cur = n & 1;
    if (cur == 1) {
      curlen += 1;
    } else {
      prevlen = (n & 2) == 0 ? 0 : curlen;
      curlen = 0;
    }
    res = max(prevlen + curlen + 1, res);
    n >>= 1;
  }
  return res;
}

int main() {
  cout << flipDaBeat(1775 - 32 - 1 + 256);
  return 0;
}

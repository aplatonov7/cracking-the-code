#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isAlmostSame (string a, string b) {
  if (abs((int)(a.size() - b.size())) > 1) return false;
  int len = min(a.size(), b.size());
  for (int i = 0; i < len; i++) {
    if (a[i] != b[i]) {
      return (
        a.substr(i + 1, string::npos) == b.substr(i + 1, string::npos) ||
        a.substr(i + 1, string::npos) == b.substr(i, string::npos) ||
        a.substr(i, string::npos) == b.substr(i + 1, string::npos)
      );
    }
  }
  return true;
}

int main() {
  string a = "abcdbfac";
  string b = "abcdbffac";
  cout << (isAlmostSame(a, b) ? "YES" : "NO") << endl;
  return 0;
}

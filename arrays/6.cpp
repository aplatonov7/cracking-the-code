#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void append(string &str, char c, int count) {
  string buff = to_string(count);
  buff.insert(0, 1, c);
  str += buff;
}

string compress(string str) {
  string res = "";
  int i = 1, count = 1;
  for (; i < str.size(); i++, count++) {
    if (str[i - 1] != str[i]) {
      append(res, str[i - 1], count);
      count = 0;
    }
  }
  append(res, str[str.size() - 1], count);
  return str.size() > res.size() ? res : str;
}

int main() {
  string str = "aabcccccaaa";
  cout << compress(str) << endl;
  return 0;
}

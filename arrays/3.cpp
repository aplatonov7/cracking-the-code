#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void replaceAll (string &str, string from, string to) {
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
}

int main() {
  string str = "some test string";
  string from = " ";
  string to = "%20";
  replaceAll(str, from, to);
  cout << str << endl;
  return 0;
}

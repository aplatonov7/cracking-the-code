#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isRotation(string a, string b) {
  if(a.size() != b.size()) return false;
  string buff = b + b;
  return buff.find(a) !=string::npos;
}

int main() {
  string a = "waterbottle";
  string b = "erbottlewat";
  cout << (isRotation(a, b) ? "YES" : "NO");
  return 0;
}

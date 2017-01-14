#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

class shelter {
  stack<string> cats;
  stack<string> dogs;
  stack<int>* latest;

public:
  void push(string name, string type) {
    if (type == "cat") {
      cats.push(name);
      latets = cats;
    } else if (type == "dog") {
      dogs.push(name);
      latests = dogs;
    }
  }
};

int main() {
  return 0;
}

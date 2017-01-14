#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class set_of_stacks {
  const int THRESHOLD = 1;
  vector<stack<int>> v;
  int index;

public:
  set_of_stacks() {
    stack<int> s;
    v.push_back(s);
    index = 0;
  }

  void push(int n) {
    if (v[index].size() == THRESHOLD) {
      stack<int> s;
      v.push_back(s);
      index += 1;
    }
    v[index].push(n);
  }

  int top() {
    return v[index].top();
  }

  void pop() {
    if (index > 0 && v[index].size() < 2) {
      v.pop_back();
      index -= 1;
    } else {
      v[index].pop();
    }
  }

  void popAt(int i) {
    if (i < 0 || i > index) return;
    if (i == index) {
      pop();
      return;
    }
    v[i].pop();
    if (v[i].empty()) {
      v.erase(v.begin() + i);
      index -= 1;
    }
  }

  bool empty() {
    return index == 0 && v[0].empty();
  }
};

int main() {
  set_of_stacks s;
  s.push(1);
  cout << s.top() << endl;
  s.push(2);
  cout << s.top() << endl;
  s.push(3);
  cout << s.top() << endl;
  s.push(4);
  cout << s.top() << endl;
  s.popAt(1);
  s.popAt(1);
  cout << s.top() << endl;
  s.popAt(1);
  cout << s.top() << endl;
  return 0;
}

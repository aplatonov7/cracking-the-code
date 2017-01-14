#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class minStack {
  stack<int> s;
  stack<int> m;

public:
  void push(int n) {
    s.push(n);
    if (m.empty() || n <= m.top()) m.push(n);
  }

  void pop() {
    if (s.top() == m.top()) m.pop();
    s.pop();
  }

  bool empty() {
    return s.empty();
  }

  int top() {
    return s.top();
  }

  int min() {
    return m.top();
  }
};

int main() {
  minStack m;
  m.push(1);
  m.push(-1);
  m.push(12);
  m.push(-5);
  m.push(14);
  m.push(-10);
  cout << m.min() << endl;
  m.pop();
  cout << m.min() << endl;
  m.pop();
  cout << m.min() << endl;
  m.pop();
  cout << m.min() << endl;
  m.pop();
  cout << m.min() << endl;
  m.pop();
  cout << m.min() << endl;
  m.pop();
  return 0;
}

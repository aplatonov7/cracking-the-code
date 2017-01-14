#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

void sortStack(stack<int> &s) {
  stack<int> buff;
  while (!s.empty()) {
    int c = s.top();
    s.pop();
    while (!buff.empty() && buff.top() > c) {
      s.push(buff.top());
      buff.pop();
    }
    buff.push(c);
  }

  while (!buff.empty()) {
    s.push(buff.top());
    buff.pop();
  }
}

int main() {
  stack<int> s;
  vector<int> input = { 1, 52, 32, -42, 52, 152, 43, 23, 11, 9, -49, 1 };
  for (int i = 0; i < input.size(); i++) s.push(input[i]);
  sortStack(s);
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  return 0;
}

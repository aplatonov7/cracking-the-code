#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ThreeStacks {
  int* data;
  int size = 3;
  int tops[3] = { -1, -1, -1 };

  void extend() {
    int* ndata = new int[size * 2];
    for (int i = 0; i < size; i++) ndata[i] = data[i];
    data = ndata;
    size *= 2;
  }
public:
  ThreeStacks() {
    data = new int[size];
  }

  void push(int n, int d) {
    int i;
    if (tops[n] == -1) {
      i = n;
    } else {
      i = tops[n] + 3;
    }
    if (i >= size) extend();
    data[i] = d;
    tops[n] = i;
  }

  void pop(int n) {
    int i = tops[n];
    if (i == -1) return;
    if (i == n) {
      tops[n] = -1;
    } else {
      tops[n] = i - 3;
    }
    data[i] = -1;
  }

  int peek(int n) {
    return data[tops[n]];
  }

  bool isEmpty(int n) {
    return tops[n] == -1;
  }
};

int main() {
  ThreeStacks t;
  t.push(0, 1);
  cout << t.peek(0) << endl;
  t.push(0, 420);
  cout << t.peek(0) << endl;
  t.push(1, 24);
  cout << t.peek(1) << endl;
  t.push(1, 524);
  cout << t.peek(1) << endl;
  t.push(2, 1526);
  cout << t.peek(2) << endl;
  t.push(2, 2325);
  cout << t.peek(2) << endl;
  cout << t.peek(0) << endl;
  cout << t.peek(1) << endl;
  cout << t.peek(2) << endl;
  t.pop(0);
  t.pop(2);
  cout << t.peek(0) << endl;
  cout << t.peek(1) << endl;
  cout << t.peek(2) << endl;
  return 0;
}

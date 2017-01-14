#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class my_queue {
  stack<int> s1;
  stack<int> s2;

  void rearrange() {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
public:
  void enq(int n) {
    s1.push(n);
  }

  void deq() {
    rearrange();
    s2.pop();
  }

  int first() {
    rearrange();
    return s2.top();
  }
};

int main() {
  my_queue q;
  q.enq(1);
  q.enq(2);
  q.enq(3);
  q.enq(4);
  cout << q.first() << endl;
  q.deq();
  cout << q.first() << endl;
  q.deq();
  cout << q.first() << endl;
  q.deq();
  cout << q.first() << endl;
  return 0;
}

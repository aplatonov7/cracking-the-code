#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct node {
  int val;
  vector<node*> adj;

  node(int val): val(val) {
    vector<node*> adj = vector<node*>(0);
  }
};

struct graph {
  map<int, node*> nodes;

public:
  int size() {
    return nodes.size();
  }

  node* get(int a) {
    node* an;
    if (nodes.find(a) == nodes.end()) {
      an = new node(a);
      nodes[a] = an;
    } else {
      an = nodes[a];
    }
    return an;
  }

  void add(int a, int b) {
    node* an = get(a);
    node* bn = get(b);
    an->adj.push_back(bn);
  }

  bool pathExists(node* a, node* b) {
    queue<node*> q;
    map<node*, bool> v;
    q.push(a);
    v[a] = true;
    while (!q.empty()) {
      node* tmp = q.front();
      q.pop();
      for (int i = 0; i < tmp->adj.size(); i++) {
        node* cur = tmp->adj[i];
        if (cur == b) return true;
        if (v.find(cur) == v.end()) {
          v[cur] = true;
          q.push(cur);
        }
      }
    }
    return false;
  }
};

int main() {
  graph g;
  g.add(1, 2);
  g.add(1, 3);
  g.add(1, 4);
  g.add(1, 5);
  g.add(3, 5);
  g.add(3, 2);
  g.add(2, 6);
  g.add(6, 7);
  g.add(7, 12);
  g.add(7, 11);
  g.add(7, 15);
  g.add(420, 600);
  cout << (g.pathExists(g.get(4), g.get(15)) ? "YEP" : "NOPE") << endl;
  return 0;
}

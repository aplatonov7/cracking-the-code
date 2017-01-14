#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct node {
  int val;
  vector<node*> adj;

  node(int val): val(val) {
    vector<node*> adj = vector<node*>(0);
  }
};

typedef map<int, node*>::iterator it_type;

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

  void topologicalSort(node* n, map<node*, int>& v, stack<node*>& s, bool& cycle) {
      v[n] = 1;
      for (int i = 0; i < n->adj.size(); i++) {
        if (v[n->adj[i]] == 0) {
          topologicalSort(n->adj[i], v, s, cycle);
        } else if (v[n->adj[i]] == 1) {
          cycle = true;
          break;
        }
      }
      v[n] = 2;
      s.push(n);
  }

  void topologicalSort() {
    map<node*, int> v;
    stack<node*> s;
    bool cycle = false;
    for (it_type it = nodes.begin(); it != nodes.end(); it++) v[it->second] = 0;

    for (it_type it = nodes.begin(); it != nodes.end() && !cycle; it++)
      if (v[it->second] == 0) topologicalSort(it->second, v, s, cycle);

    if (cycle) {
      cout << "Cycle found";
    } else {
      while (!s.empty()) {
        cout << s.top()->val << ' ';
        s.pop();
      }
    }
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
  g.topologicalSort();
  return 0;
}

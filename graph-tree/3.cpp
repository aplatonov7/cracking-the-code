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
  node* left;
  node* right;

  node(int val): val(val) {
    left = nullptr;
    right = nullptr;
  }
};

node* buildBST(vector<int>& arr, int s, int e, int depth) {
  if (s > e) return nullptr;
  int mid = (s + e) / 2;
  node* root = new node(arr[mid]);
  root->left = buildBST(arr, s, mid - 1, depth + 1);
  root->right = buildBST(arr, mid + 1, e, depth + 1);
  return root;
}

node* buildBST(vector<int>& arr) {
  return buildBST(arr, 0, arr.size() - 1, 0);
}

void traverse(node* root, map<int, vector<node*>>& m, int depth) {
  if (root == nullptr) return;
  if (m.find(depth) == m.end()) m[depth] = vector<node*>(0);
  traverse(root->left, m, depth + 1);
  m[depth].push_back(root);
  traverse(root->right, m, depth + 1);
}

vector<vector<node*>> getDepthLists(node* root) {
  map<int, vector<node*>> m;
  traverse(root, m, 0);
  int p = 0;
  vector<vector<node*>> res;
  while (m.find(p) != m.end()) res.push_back(m[p++]);
  return res;
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  vector<vector<node*>> v = getDepthLists(root);
  for (int i = 0; i < v.size(); i++) {
    cout << "Depth " << i << ": ";
    for (int j = 0; j < v[i].size(); j++) cout << v[i][j]->val << ' ';
    cout << endl;
  }
  return 0;
}

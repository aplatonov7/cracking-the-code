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

void print(node* root) {
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    if (q.front()->left != nullptr) q.push(q.front()->left);
    if (q.front()->right != nullptr) q.push(q.front()->right);
    cout << q.front()->val << ' ';
    q.pop();
  }
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  print(root);
  return 0;
}

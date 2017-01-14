#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node* parent;

  node(int val): val(val) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }
};

node* buildBST(vector<int>& arr, int s, int e, int depth) {
  if (s > e) return nullptr;
  int mid = (s + e) / 2;
  node* root = new node(arr[mid]);
  root->left = buildBST(arr, s, mid - 1, depth + 1);
  root->right = buildBST(arr, mid + 1, e, depth + 1);
  if (root->left != nullptr) root->left->parent = root;
  if (root->right != nullptr) root->right->parent = root;
  return root;
}

node* buildBST(vector<int>& arr) {
  return buildBST(arr, 0, arr.size() - 1, 0);
}

int getDepth(node* a) {
  int res = 0;
  while (a->parent != nullptr) a = a->parent, res += 1;
  return res;
}

node* findAncestor(node* a, node* b) {
  int da = getDepth(a);
  int db = getDepth(b);
  if (da > db) while (--da - db >= 0) a = a->parent;
  else if (db > da) while (--db - da >= 0) b = b->parent;
  while (a != b) {
    a = a->parent;
    b = b->parent;
  }
  return a;
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  cout << (findAncestor(root->right->right->right, root->right->left)->val);
  return 0;
}

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

bool checkBST(node* root, int l, int u) {
  if (root == nullptr) return true;
  if (root->val < l || root->val > u) return false;
  return checkBST(root->left, l, root->val) && checkBST(root->right, root->val, u);
}

bool checkBST(node* root) {
  return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  cout << (checkBST(root) ? "YAY" : "NAY") << endl;
  return 0;
}

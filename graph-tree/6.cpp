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

node* findSuccessor(node* root) {
  if (root->right != nullptr) {
    node* res = root->right;
    while (res->left != nullptr) res = res->left;
    return res;
  } else if(root->parent != nullptr) {
    node* prev = root;
    node* cur = root;
    while (cur->parent != nullptr) {
      cur = cur->parent;
      if (cur ->left == prev) return cur;
      prev = cur;
    }
  }
  return nullptr;
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  node* suc = findSuccessor(root->right->right);
  if (suc != nullptr) cout << suc->val;
  return 0;
}

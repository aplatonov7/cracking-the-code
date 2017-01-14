#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include <list>
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

string preorder(node* root) {
  if (root == nullptr) return "null";
  string res = "";
  res += to_string(root->val);
  res += preorder(root->left);
  res += preorder(root->right);
  return res;
}

bool contains(node* a, node* b) {
  string pa = preorder(a);
  string pb = preorder(b);
  return pa.find(pb) != string::npos;
}

bool match(node* a, node* b) {
  if (a == nullptr && b == nullptr) {
    return true;
  } else if (a == nullptr || b == nullptr) {
    return false;
  } else if (a->val != b->val) {
    return false;
  }
  return match(a->left, b->left) && match(a->right, b->right);
}

bool containsAlt(node* a, node *b) {
  if (a == nullptr) return false;
  if (a->val == b->val && match(a, b)) return true;
  return containsAlt(a->left, b) || containsAlt(a->right, b);
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  vector<int> arr2 = { 1, 2, 3, 4 };
  node* root = buildBST(arr);
  node* root2 = buildBST(arr2);
  cout << (contains(root, root2) ? "YAY" : "NAY") << endl;
  cout << (containsAlt(root, root2) ? "YAY" : "NAY") << endl;
  return 0;
}

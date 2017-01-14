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

int checkBalanced(node* root) {
  if (root == nullptr) return 0;
  int dl = checkBalanced(root->left);
  int dr = checkBalanced(root->right);
  if (dl == -1 || dr == -1 || abs(dl - dr) > 1) return -1;
  return max(dl, dr) + 1;
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  cout << checkBalanced(root) << endl;
  root->right->right->right->right = new node(10);
  cout << checkBalanced(root) << endl;
  return 0;
}

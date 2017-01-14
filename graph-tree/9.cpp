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

void weave(
  list<node*> left,
  list<node*> right,
  vector<list<node*>>& res,
  list<node*> prefix
) {
  if (left.size() == 0 || right.size() == 0) {
    prefix.insert(prefix.end(), left.begin(), left.end());
    prefix.insert(prefix.end(), right.begin(), right.end());
    res.push_back(prefix);
    return;
  }

  node* headLeft = left.front();
  left.pop_front();
  prefix.push_back(headLeft);
  weave(left, right, res, prefix);
  prefix.pop_back();
  left.push_front(headLeft);

  node* headRight = right.front();
  right.pop_front();
  prefix.push_back(headRight);
  weave(left, right, res, prefix);
  prefix.pop_back();
  right.push_front(headRight);
}

vector<list<node*>> getArrays(node* root) {
  vector<list<node*>> res;
  if (root == nullptr) {
    res.push_back(list<node*>(0));
    return res;
  }
  list<node*> prefix = { root };
  vector<list<node*>> l = getArrays(root->left);
  vector<list<node*>> r = getArrays(root->right);
  for (list<node*> left : l)
    for (list<node*> right: r)
      weave(left, right, res, prefix);
  return res;
}

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node* root = buildBST(arr);
  vector<list<node*>> arrs = getArrays(root);
  for (list<node*> arr : arrs) {
    for (node* n : arr) cout << n->val << ' ';
    cout << endl;
  }
  return 0;
}

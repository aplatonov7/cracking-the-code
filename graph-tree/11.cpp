#include <cmath>
#include <cstdio>
#include <cstdlib>
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

class BST {
  node* root;
  int size;

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

  void traverse(node* n) {
    if (n == nullptr) return;
    traverse(n->left);
    cout << n->val << ' ';
    traverse(n->right);
  }

  void insert(node* root, node* n) {
    if (n->val <= root->val) {
      if (root->left == nullptr) {
        root->left = n;
        n->parent = root;
        size += 1;
      } else {
        insert(root->left, n);
      }
    } else {
      if (root->right == nullptr) {
        root->right = n;
        n->parent = root;
        size += 1;
      } else {
        insert(root->right, n);
      }
    }
  }

  node* find(node* root, int val) {
    if (root == nullptr) return nullptr;
    if (root->val == val) return root;
    if (val <= root->val)
      return find(root->left, val);
    else
      return find(root->right, val);
  }

  void deleteNode(node* n) {
    if (n == nullptr) return;
    node* left = n->left;
    node* right = n->right;
    node* parent = n->parent;
    if (left != nullptr && right != nullptr) {
      while (right->left != nullptr) right = right->left;
      n->val = right->val;
      deleteNode(right);
    } else {
      size -= 1;
      if (parent == nullptr) {
        root = left != nullptr ? left : right;
      } else if (parent->left == n) {
        parent->left = left != nullptr ? left : right;
      } else {
        parent->right = left != nullptr ? left : right;
      }
    }
  }

  node* findByIndex(node* n, int i, int& cur) {
    if (n == nullptr) return nullptr;
    if (i == cur) return n;
    cur += 1;
    node* l = findByIndex(n->left, i, cur);
    node* r = findByIndex(n->right, i, cur);
    return l != nullptr ? l : r;
  }

  node* findByIndex(node* n, int i) {
    int cur = 0;
    return findByIndex(n, i, cur);
  }
public:
  BST() { root = nullptr; size = 0; };
  BST(vector<int> arr) {
    sort(arr.begin(), arr.end());
    root = buildBST(arr, 0, arr.size() - 1, 0);
    size = arr.size();
  }

  int getSize() {
    return size;
  }

  void insert(int val) {
    node* n = new node(val);
    insert(root, n);
  }

  node* find(int val) {
    return find(root, val);
  }

  void deleteNode(int val) {
    node* n = find(val);
    deleteNode(n);
  }

  node* getRandomNode() {
    int n = rand() % size;
    return findByIndex(root, n);
  }

  void print() {
    traverse(root);
    cout << endl;
  }
};

int main() {
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  BST t = BST(arr);
  t.insert(5);
  t.insert(15);
  t.insert(-1);
  t.insert(17);
  t.print();
  map<node*, int> test;
  for (int i = 0; i < 1000000; i++) {
    node* n = t.getRandomNode();
    if (test.find(n) == test.end()) test[n] = 0;
    test[n] += 1;
  }

  for (map<node*, int>::iterator it = test.begin(); it != test.end(); it++) {
    cout << it->first->val << ' ' << it->second << endl;
  }
  return 0;
}

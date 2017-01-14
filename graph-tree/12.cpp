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

  int waysToSum(node* n, int&target, int sum) {
    if (n == nullptr) return 0;
    sum += n->val;
    int res = 0;
    if (sum == target) res += 1;
    res += waysToSum(n->left, target, sum);
    res += waysToSum(n->right, target, sum);
    return res;
  }

  int waysToSum(node* n, int& target) {
    if (n == nullptr) return 0;
    int res = 0;
    res += waysToSum(n, target, 0);
    res += waysToSum(n->left, target);
    res += waysToSum(n->right, target);
    return res;
  }

  int waysToSumAlt(node* n, int& target, int runningSum, map<int, int>& paths) {
    if (n == nullptr) return 0;
    runningSum += n->val;
    int diff = runningSum - target;
    int res = 0;
    if (paths.find(diff) != paths.end()) res += paths[diff];
    if (runningSum == target) res += 1;

    if (paths.find(runningSum) == paths.end()) paths[runningSum] = 1;
    else paths[runningSum] += 1;
    res += waysToSumAlt(n->left, target, runningSum, paths);
    res += waysToSumAlt(n->right, target, runningSum, paths);
    paths[runningSum] -= 1;

    return res;
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

  int waysToSum(int sum) {
    return waysToSum(root, sum);
  }

  int waysToSumAlt(int sum) {
    map<int, int> paths;
    return waysToSumAlt(root, sum, 0, paths);
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
  cout << t.waysToSum(17) << endl;
  cout << t.waysToSumAlt(17) << endl;
  return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  Node* next;
  int data;

  Node(int data): data(data) {
    next = nullptr;
  }
};

void append(Node* head, Node* data) {
  while(head->next != nullptr) head = head->next;
  head->next = data;
}

void print(Node* head) {
  while(head != nullptr) {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << endl;
}

Node* find(Node* head, int data) {
  if (head == nullptr || head->data == data) return head;
  return find(head->next, data);
}

int getLength(Node* head) {
  int l = 0;
  while (head != nullptr) {
    l++;
    head = head->next;
  }
  return l;
}

Node* kthFromLast(Node* head, int k, int& i) {
  if (head == nullptr) return nullptr;
  Node* nd = kthFromLast(head->next, k, i);
  i += 1;
  if (i == k) return head;
  return nd;
}

Node* kthFromLast(Node* head, int k) {
  int i = 0;
  return kthFromLast(head, k, i);
}

int main() {
  Node* head = new Node(1);
  append(head, new Node(2));
  append(head, new Node(3));
  append(head, new Node(4));
  append(head, new Node(5));
  append(head, new Node(6));
  append(head, new Node(7));
  append(head, new Node(8));
  append(head, new Node(9));
  print(head);
  cout << kthFromLast(head, 4)->data;
  return 0;
}

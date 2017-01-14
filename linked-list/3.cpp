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

void deleteNode(Node* nd) {
  if (nd == nullptr || nd->next == nullptr) return;
  nd->data = nd->next->data;
  nd->next = nd->next->next;
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
  Node* target = find(head, 4);
  deleteNode(target);
  print(head);
  return 0;
}

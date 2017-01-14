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

void removeAll(Node* head, int data) {
  if (head == nullptr) return;
  Node* prev = head;
  Node* cur = head->next;
  while (cur != nullptr) {
    if (cur->data == data) {
      prev->next = cur->next;
    } else {
      prev = cur;
    }
    cur = cur->next;
  }
}

int main() {
  Node* head = new Node(1);
  append(head, new Node(2));
  append(head, new Node(2));
  append(head, new Node(2));
  append(head, new Node(3));
  append(head, new Node(3));
  append(head, new Node(4));
  append(head, new Node(4));
  append(head, new Node(4));
  print(head);
  removeAll(head, 2);
  print(head);
  return 0;
}

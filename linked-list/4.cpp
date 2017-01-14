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

Node* partition(Node* head, int val) {
  if (head == nullptr || head->next == nullptr) return head;
  Node* prev = head;
  Node* cur = head->next;
  while(cur != nullptr) {
    if (cur->data < val) {
      prev->next = cur->next;
      cur->next = head;
      head = cur;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
  return head;
}

int main() {
  Node* head = new Node(53);
  append(head, new Node(8));
  append(head, new Node(15));
  append(head, new Node(2));
  append(head, new Node(5));
  append(head, new Node(457));
  append(head, new Node(42));
  append(head, new Node(2));
  append(head, new Node(52));
  print(head);
  head = partition(head, 42);
  print(head);
  return 0;
}

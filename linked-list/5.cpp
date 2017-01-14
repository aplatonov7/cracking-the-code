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

Node* sumLists(Node* a, Node* b) {
  Node* res = new Node(0);
  int carry = 0;
  while (a != nullptr || b != nullptr) {
    int buff = carry;
    if (a != nullptr) {
      buff += a->data;
      a = a->next;
    }
    if (b != nullptr) {
      buff += b->data;
      b = b->next;
    }
    carry = buff / 10;
    append(res, new Node(buff % 10));
  }
  if (carry > 0) append(res, new Node(carry));
  return res->next;
}

Node* padWithZeroes(Node* head, int c) {
  while (c-- > 0) {
    Node* n = new Node(0);
    n->next = head;
    head = n;
  }
  return head;
}

Node* prepend(Node* head, Node* n) {
  if (head == nullptr) return n;
  n->next = head;
  return n;
}

int sumListsStraight(Node* a, Node* b, Node* &dest) {
  if (a == nullptr) return 0;
  int buff = sumListsStraight(a->next, b->next, dest) + a->data + b->data;
  dest = prepend(dest, new Node(buff % 10));
  return buff / 10;
}

Node* sumListsStraight(Node* a, Node* b) {
  Node* dest = nullptr;
  int al = getLength(a);
  int bl = getLength(b);
  if (al > bl) b = padWithZeroes(b, al - bl);
  else if (bl > al) a = padWithZeroes(a, bl - al);
  int carry = sumListsStraight(a, b, dest);
  if (carry > 0) return prepend(dest, new Node(carry));
  return dest;
}

int main() {
  Node* a = new Node(9);
  append(a, new Node(7));
  append(a, new Node(8));
  Node* b = new Node(6);
  append(b, new Node(8));
  append(b, new Node(5));
  append(b, new Node(5));
  append(b, new Node(5));
  print(a);
  print(b);
  Node* res = sumListsStraight(a, b);
  print(res);
  return 0;
}

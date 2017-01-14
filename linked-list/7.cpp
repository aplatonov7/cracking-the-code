#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
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

Node* reverse(Node* head) {
  Node* prev = nullptr;
  Node* cur = head;
  while (cur != nullptr) {
    Node* tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
  }
  return prev;
}

Node* intersection(Node* a, Node* b) {
  Node* at = a;
  Node* bt = b;
  int al = 1, bl = 1;

  while (at->next != nullptr) {
    al += 1;
    at = at->next;
  }

  while (bt->next != nullptr) {
    bl += 1;
    bt = bt->next;
  }

  if (at != bt) return nullptr;
  if (al > bl) for (; al != bl; al--) a = a->next;
  else if (bl > al) for (; al != bl; bl--) b = b->next;

  while (a != nullptr) {
    if (a == b) return a;
    a = a->next;
    b = b->next;
  }

  return nullptr;
}

int main() {
  Node* a = new Node(1);
  Node* in = new Node(4);
  append(a, new Node(2));
  append(a, new Node(3));
  append(a, in);
  append(a, new Node(5));
  append(a, new Node(6));
  append(a, new Node(7));
  Node* b = new Node(54);
  append(b, new Node(12));
  append(b, new Node(15));
  append(b, new Node(17));
  append(b, in);
  print(a);
  print(b);
  cout << (intersection(a, b) != nullptr ? "THEY DO" : "HELL NO") << endl;
  return 0;
}

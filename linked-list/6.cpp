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

bool isPalindrome(Node* head) {
  Node* slow = head;
  Node* fast = head;
  stack<int> s;
  while (fast != nullptr) {
    s.push(slow->data);
    cout << s.top() << endl;
    if (fast->next == nullptr) fast = nullptr;
    else {
      fast = fast->next->next;
      slow = slow->next;
    }
  }
  while(slow != nullptr) {
    if (slow->data != s.top()) return false;
    s.pop();
    slow = slow->next;
  }
  return true;
}

int main() {
  Node* a = new Node(1);
  append(a, new Node(2));
  append(a, new Node(3));
  append(a, new Node(4));
  append(a, new Node(5));
  append(a, new Node(4));
  append(a, new Node(3));
  append(a, new Node(2));
  append(a, new Node(1));
  print(a);
  cout << (isPalindrome(a) ? "YES" : "NO");
  return 0;
}

/*************************************************************************
	> File Name: reverse_linklist.cpp
	> Author: 宫局仁的供橘人
	> Motto: Barefoot makes wheels
	> Created Time: Wed Jan 25 13:32:57 2023
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

struct Node {
  Node(int val, Node *next = nullptr) : val(val), next(next) {} 
  int val;
  Node *next;
};

ostream &operator<<(ostream &out, Node *head) {
  for (Node *p = head; p; p = p->next) {
    out << p->val << "->";
  }
  return out << "NULL";
}

void reverseV1(Node *head) {
  //TODO
  //head insert method
  if (head == NULL) return ; 
  return ;
}

/*
void reverseV2(Node *head) {
  //reverse print linklist
  if (head == NULL) return ; 
  reverseV2(head->next);
  printf("%d->", head->val);
  return ;
}
*/

Node *reverseV2(Node *head) {
  //reverse linklist
  if (head == NULL || head->next == NULL) return head; 
  Node *tail = head->next, *new_head = reverseV2(head->next);
  head->next = tail->next;
  tail->next = head;
  return new_head;
}

Node *reverseV3(Node *head, int n) {
  //reverse linklist
  if (n == 1 || head == NULL || head->next == NULL) return head; 
  Node *tail = head->next, *new_head = reverseV3(head->next, n - 1);
  head->next = tail->next;
  tail->next = head;
  return new_head;
}

int main() {
  Node *head = new Node(1);
  cout << head << endl;
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  cout << head << endl;

  //cout << endl << "reverse: ";
  //Node *new_head1 = reverseV2(head);
  //cout << new_head1 << endl;

  cout << endl << "reverse_N: ";
  Node *new_head2 = reverseV3(head, 2);
  cout << new_head2 << endl;
  return 0;
}

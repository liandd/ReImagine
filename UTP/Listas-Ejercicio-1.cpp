#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  struct node *sig;
};

struct node *makeLinkedList(int n) {
  struct node *head, *newNode;
  head = NULL;
  while (n >= 1) {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = n;
    newNode->sig = head;
    head = newNode;
    n--;
  }
  return head;
}

int main() {}

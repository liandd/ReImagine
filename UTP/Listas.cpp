#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  struct node *sig;
};

int main() {
  struct node *head, *q;
  head = (struct node *)malloc(sizeof(struct node));
  head->key = 1;
  q = (struct node *)malloc(sizeof(struct node));
  q->key = 2;
  head->sig = q;
  q->sig = (struct node *)malloc(sizeof(struct node));
  q->sig->key = 3;
  q->sig->sig = NULL;
  printf("%d -> %d -> %d\n", head->key, head->sig->key, head->sig->sig->key);
  return 0;
}

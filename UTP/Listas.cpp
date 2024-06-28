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
<<<<<<< HEAD
  printf("%d %d %d\n", head->key, head->sig->key, head->sig->sig->key);
=======
  q->sig->sig = NULL;
  printf("%d -> %d -> %d\n", head->key, head->sig->key, head->sig->sig->key);
>>>>>>> 37bb1d450fea3bb94edaf3a78eac13750159fedb
  return 0;
}

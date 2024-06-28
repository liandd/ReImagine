#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  struct node *sig;
};

int main() {
  struct node *head, *newNode, *actualNode;
  int n = 100;
  head = NULL;
  while (n >= 1) {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = n;
    newNode->sig = head;
    head = newNode;
    n--;
  }
  actualNode = head;
  while (actualNode != NULL) {
<<<<<<< HEAD
    printf("%d ", actualNode->key);
=======
    printf("%d -> ", actualNode->key);
>>>>>>> 37bb1d450fea3bb94edaf3a78eac13750159fedb
    actualNode = actualNode->sig;
  }
  printf("NULL.\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define myNegativeInfinite -9223372036854775807
#define myPositiveInfinite 9223372036854775807
#define TOP_NUMBER 1000000
#define lli long long int

typedef struct {
  lli key;
  char name[22];
} person;

int Parent(int i) { return i >> 1; }

int Left(int i) { return i << 1; }

int Right(int i) { return (i << 1) + 1; }

void MinHeapify(person Q[], int i, int heapSize) {
  int l = Left(i);
  int r = Right(i);
  int least;
  person temp;
  if ((l <= heapSize) && (Q[l].key < Q[i].key))
    least = l;
  else
    least = i;
  if ((r <= heapSize) && (Q[r].key < Q[least].key))
    least = r;
  if (least != i) {
    temp = Q[i];
    Q[i] = Q[least];
    Q[least] = temp;
    MinHeapify(Q, least, heapSize);
  }
}

person MinPQ_Minimun(person Q[]) { return Q[1]; }

person MinPQ_Etract(person Q[], int *heapSize) {
  person min;
  min.key = myNegativeInfinite;
  if (*heapSize < 1) {
  } else {
    min = Q[1];
    Q[1] = Q[*heapSize];
    (*heapSize)--;
    MinHeapify(Q, 1, *heapSize);
  }
  return min;
}

void MinPQ_DecreaseKey(person Q[], int i, person key) {
  person temp;
  if (key.key > Q[i].key) {
  } else {
    Q[i] = key;
    while ((i > 1) && (Q[Parent(i)].key > Q[i].key)) {
      temp = Q[i];
      Q[i] = Q[Parent(i)];
      Q[Parent(i)] = temp;
      i = Parent(i);
    }
  }
}

void MinPQ_Insert(person Q[], person key, int *heapSize) {
  (*heapSize)++;
  Q[*heapSize].key = myPositiveInfinite;
  MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
  int element, ID = 0, heapSize = 0, priority = 0;
  char name[22];
  person Q[TOP_NUMBER + 5], temp;
  while (scanf("%s", name) != EOF) {
    ID++;
    if (name[0] != 'V') {
      scanf("%d", &priority);
      temp.key = (lli)(1001 - priority) * 1000000 + ID;
      strcpy(temp.name, name);
      MinPQ_Insert(Q, temp, &heapSize);
    } else {
      temp = MinPQ_Etract(Q, &heapSize);
      printf("%s\n", temp.name);
    }
  }

  return 0;
}

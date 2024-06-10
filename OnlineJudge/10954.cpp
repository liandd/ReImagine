#include <bits/stdc++.h>
using namespace std;
#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAT 5000

int Parent(int i) { return i >> 1; }

int Left(int i) { return i << 1; }

int Right(int i) { return (i << 1) + 1; }

void MinHeapify(int Q[], int i, int heapSize) {
  int l = Left(i);
  int r = Right(i);
  int least, temp;
  if ((l <= heapSize) && (Q[l] < Q[i]))
    least = l;
  else
    least = i;
  if ((r <= heapSize) && (Q[r] < Q[least]))
    least = r;

  if (least != i) {
    temp = Q[i];
    Q[i] = Q[least];
    Q[least] = temp;
    MinHeapify(Q, least, heapSize);
  }
}

int MinPQ_Minimun(int Q[]) { return Q[1]; }

int MinPQ_Etract(int Q[], int *heapSize) {
  int min = myNegativeInfinite;
  if (*heapSize < 1) {
  } else {
    min = Q[1];
    Q[1] = Q[*heapSize];
    (*heapSize)--;
    MinHeapify(Q, 1, *heapSize);
  }
  return min;
}

void MinPQ_DecreaseKey(int Q[], int i, int key) {
  int temp;
  if (key > Q[i]) {
  } else {
    Q[i] = key;
    while ((i > 1) && Q[Parent(i)] > Q[i]) {
      temp = Q[i];
      Q[i] = Q[Parent(i)];
      Q[Parent(i)] = temp;
      i = Parent(i);
    }
  }
}

void MinPQ_Insert(int Q[], int key, int *heapSize) {
  (*heapSize)++;
  Q[*heapSize] = myPositiveInfinite;
  MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
  int n, Q[MAT + 2], element, id, result, temp, temp2;
  while (scanf("%d", &n) && (n > 0)) {
    int heapSize = 0;
    for (id = 1; id <= n; id++) {
      scanf("%d", &element);
      MinPQ_Insert(Q, element, &heapSize);
    }
    result = 0;
    temp = 0;
    temp2 = 0;
    for (id = 1; id < n; id++) {
      temp = MinPQ_Etract(Q, &heapSize);
      temp2 = MinPQ_Etract(Q, &heapSize);
      // printf("%d+%d\n", temp, temp2);
      temp += temp2;
      result += temp;
      MinPQ_Insert(Q, temp, &heapSize);
    }
    printf("%d\n", result);
  }
  return 0;
}

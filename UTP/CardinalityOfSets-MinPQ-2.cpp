#include <bits/stdc++.h>
using namespace std;
#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAT 1000000

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
    while ((i > 1) && (Q[Parent(i)] > Q[i])) {
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
  int m, n, QA[MAT + 5], QB[MAT + 5], idElement, element, elementA, elementB,
      intersect;
  int heapSizeA, heapSizeB;
  while (scanf("%d %d", &m, &n) && (m > 0) && (n > 0)) {
    heapSizeA = 0;
    heapSizeB = 0;
    intersect = 0;

    for (idElement = 1; idElement <= m; idElement++) {
      scanf("%d", &element);
      MinPQ_Insert(QA, element, &heapSizeA);
    }
    for (idElement = 1; idElement <= n; idElement++) {
      scanf("%d", &element);
      MinPQ_Insert(QB, element, &heapSizeB);
    }
    while (heapSizeA >= 1 && heapSizeB >= 1) {
      elementA = MinPQ_Minimun(QA);
      elementB = MinPQ_Minimun(QB);
      if (elementA == elementB) {
        intersect++;
        elementA = MinPQ_Etract(QA, &heapSizeA);
        elementB = MinPQ_Etract(QB, &heapSizeB);
      } else {
        if (elementA > elementB)
          elementB = MinPQ_Etract(QB, &heapSizeB);
        else
          elementA = MinPQ_Etract(QA, &heapSizeA);
      }
    }
    printf("%d %d %d %d\n", m - intersect, intersect, n - intersect,
           m + n - intersect);
  }
  return 0;
}

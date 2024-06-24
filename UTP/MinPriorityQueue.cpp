// Implementacion de una Cola de minima Prioridad
#include <bits/stdc++.h>
using namespace std;
#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAT 1000

int heapSize = 0;

int Parent(int i) { return i >> 1; }

int Left(int i) { return i << 1; }

int Right(int i) { return (i << 1) + 1; }

void MinHeapify(int Q[], int i) {
  int l, r, least, temp;
  l = Left(i);
  r = Right(i);
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
    MinHeapify(Q, least);
  }
}

int MinPQ_Minimun(int Q[]) { return Q[1]; }

int MinPQ_Etract(int Q[]) { // No tengo la equis
  int min = myNegativeInfinite;
  if (heapSize < 1) {
    // Error "heap underflow"
    printf("Heap undeflow.\n");
  } else {
    min = Q[1];
    Q[1] = Q[heapSize];
    heapSize--;
    MinHeapify(Q, 1);
  }
  return min;
}

void MinPQ_DecreaseKey(int Q[], int i, int key) {
  int temp;
  if (key > Q[i]) {
    printf("New key is higher.\n");
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

void MinPQ_Insert(int Q[], int key) {
  heapSize++;
  Q[heapSize] = myPositiveInfinite;
  MinPQ_DecreaseKey(Q, heapSize, key);
}

int main() {
  // Se definen 2 operaciones insertar y sacar
  int operation, element, Q[MAT + 2]; // Operation tiene insertar o sacar
  heapSize = 0;
  while (scanf("%d", &operation) != EOF) {
    if (operation == 1) { // Insertar
      scanf("%d", &element);
      MinPQ_Insert(Q, element);
    } else {
      if (operation == 2) { // Sacar elemento
        element = MinPQ_Etract(Q);
        if (element == myNegativeInfinite) {
          printf("Empty Min Priority Queue.\n");
        } else {
          printf("%d\n", element);
        }
      } else {
        printf("Bad use!\n 1. Insert\n 2. Grab Element\n");
      }
    }
  }
  return 0;
}

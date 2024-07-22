#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define myPositiveInfinite 100
#define myNegativeInfinite -100
#define MAXT 1000000

typedef struct {
    char name[21];
    long long int key;
} person;

int Parent(int i) {
    return i >> 1;
}

int Left(int i) {
    return i << 1;
}

int Right(int i) {
    return (i << 1) + 1;
}

void MinHeapify(person P[], int i, int heapSize) {
    int l, r, smallest;
    person temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (P[l].key < P[i].key))
        smallest = l;
    else
        smallest = i;
    if((r <= heapSize) && (P[r].key < P[smallest].key))
        smallest = r;
    if(smallest != i) {
        temp = P[i];
        P[i] = P[smallest];
        P[smallest] = temp;
        MinHeapify(P, smallest, heapSize);
    }
}

person MinPQ_Minimum(person P[]) {
    return P[1];
}

person MinPQ_Extract(person P[], int *heapSize) {
    person min;
    min.key = myPositiveInfinite;
    if (*heapSize < 1)
        printf("Heap underflow.\n");
    else {
        min = P[1];
        P[1] = P[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(P, 1, *heapSize);
    }
    return min;
}

void MinPQ_DecreaseKey(person P[], int i, person key) {
    person temp;
    if (key.key > P[i].key)
        printf("New key is higher than current key.\n");
    else {
        P[i] = key;
        while ((i > 1) && (P[Parent(i)].key > P[i].key)) {
            temp = P[i];
            P[i] = P[Parent(i)];
            P[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(person P[], person key, int *heapSize) {
    *heapSize = *heapSize + 1;
    P[*heapSize].key = myPositiveInfinite;
    MinPQ_DecreaseKey(P, *heapSize, key);
}

int main() {
    int heapSize = 0, idLine = 0;
    char name[21];
    person P[MAXT + 1], addUser, next;
    long long int priority;

    while (scanf("%s", name) != EOF)
    {
        idLine++;
        if (strcmp(name, "V") == 0)
        {
            if (heapSize == 0)
                printf("\n");
            else
            {
                next = MinPQ_Extract(P, &heapSize);
                printf("%s\n", next.name);
            }
        }
        else
        {
            strcpy(addUser.name, name);
            scanf("%lld", &priority);
            addUser.key = (long long int)(10001 - priority)*10000000 + idLine;
            MinPQ_Insert(P, addUser, &heapSize);
        }
    }

    return 0;
}

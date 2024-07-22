#include <bits/stdc++.h>
using namespace std;

#define myNegativeInfinite -9223372036854775807LL
#define myPositiveInfinite 9223372036854775807LL
#define TOP_NUMBER 1000000
#define lli long long int

typedef struct {
    lli key;
    string name;
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

person MinPQ_Minimum(person Q[]) { return Q[1]; }

person MinPQ_Extract(person Q[], int *heapSize) {
    person min;
    min.key = myNegativeInfinite;
    if (*heapSize < 1) {
        cout << endl;
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
        cout << "New key is greater than current key" << endl;
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
    int heapSize = 0, priority = 0;
    char name[22];
    person Q[TOP_NUMBER + 5], temp;
    string line;

    int ID = 0;  // To maintain order of insertion
    
    while (getline(cin, line)) {
        if (line[0] == 'V') {
            if (heapSize > 0) {
                temp = MinPQ_Extract(Q, &heapSize);
                cout << temp.name << endl;
            } else {
                cout << endl;
            }
        } else {
            istringstream iss(line);
            iss >> name >> priority;
            ID++;
            temp.key = (lli)(1001 - priority) * 1000000 + ID;
            temp.name = string(name);
            MinPQ_Insert(Q, temp, &heapSize);
        }
    }
    return 0;
}

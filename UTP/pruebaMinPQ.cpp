#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1005  // Adjust as needed
#define LARGE_NUMBER 1000000
#define INF INT_MAX

typedef struct {
    int value;
    long long key;
} Element;

Element heap[MAXN];
int heapSize = 0;
int count = 0;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heapSize && heap[left].key < heap[smallest].key)
        smallest = left;

    if (right < heapSize && heap[right].key < heap[smallest].key)
        smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapify(smallest);
    }
}

void insert(Element element) {
    if (heapSize == MAXN) {
        printf("Heap overflow\n");
        return;
    }

    heap[heapSize] = element;
    int current = heapSize;
    heapSize++;

    while (current != 0 && heap[(current - 1) / 2].key > heap[current].key) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

Element extractMin() {
    if (heapSize <= 0)
        return (Element){.value = -1, .key = INF};

    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    Element root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    minHeapify(0);

    return root;
}

int main() {
    int elements[] = {1,100,20,30};  // Sample elements
    int n = sizeof(elements) / sizeof(elements[0]);
    int maxElement = 1000;

    for (int i = 0; i < n; i++) {
        int x = elements[i];
        long long key = (maxElement + 1 - x) * LARGE_NUMBER + count++;
        Element element = {.value = x, .key = key};
        insert(element);
    }

    // Extract elements to see the order
    printf("Extracted elements in order:\n");
    while (heapSize > 0) {
        Element minElement = extractMin();
        printf("Value: %d, Key: %lld\n", minElement.value, minElement.key);
    }

    return 0;
}


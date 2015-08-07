#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) ((i)>>1)
#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)+1)

int size = 0;

void printHeap(int * A, int n);
void swap(int *, int *);
void maxHeapify(int * A, int i);
void buildHeap(int * A);
void heapSort(int * A);

int main() {
    int i;
    scanf("%d", &size);
    int * A = (int *) malloc((size+1) * sizeof(int));
    A[0] = 0;
    for (i=1; i<=size; i++) {
        scanf("%d", &A[i]);
    }
    buildHeap(A);
    printHeap(A, size);
    int n = size;
    heapSort(A);
    printHeap(A, n);
    return 0;
}

void printHeap(int * A, int n) {
    int i;
    for (i=1; i<=n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int * i, int * j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void maxHeapify(int * A, int i) {
    int l, r, lar=i;
    l = LEFT(i);
    r = RIGHT(i);
    if ((l <= size) && (A[l] > A[lar]))
        lar = l;
    if ((r <= size) && (A[r] > A[lar]))
        lar = r;
    if (lar != i) {
        swap(&A[i], &A[lar]);
        maxHeapify(A, lar);
    }
}

void buildHeap(int * A) {
    int i;
    for (i=(size/2); i>0; i--) {
        maxHeapify(A, i);
    }
}

void heapSort(int * A) {
    int i;
    buildHeap(A);
    for (i=size; i>1; i--) {
        swap(&A[1], &A[i]);
        size -= 1;
        maxHeapify(A, 1);
    }
}

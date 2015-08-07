#include <stdio.h>

void swap(int * a, int * b);
void quick(int * A, int l, int r);

int main () {
    int i, n;
    scanf("%d", &n);
    int A[n];
    for (i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    quick(A, 0, n-1);
    printf("\n\n");
    for (i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

void swap(int * a, int * b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

void quick(int * A, int l, int r) {
    int i, b;
    if (r-l < 1) {
        return;
    }
    b = l + 1;
    for (i=l+1; i<=r; i++) {
        if (A[i] <= A[l]) {
            swap(&A[b], &A[i]); 
            b++;
        }
    }
    swap(&A[l], &A[b-1]);
    quick(A, l, b-1);
    quick(A, b, r);
}


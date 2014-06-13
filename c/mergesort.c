#include <stdio.h>
#include <stdlib.h>

void merge(int [], int, int, int);
void sort(int[], int, int);
 
int main(int argc, char * argv[]) {
    int i, size;
    size = atoi(argv[1]);
    int A[size];
    for (i=0; i<size; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, 0, size-1);
    for (i=0; i<size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

void merge(int A[], int start, int mid, int end) {
    int sizeL = mid - start + 1;
    int sizeM = end - mid;
    int L[sizeL], M[sizeM];
    int i, j, k;
    /* Split the array A[] into L[] and M[] */
    for (i=0; i<sizeL; i++) {
        L[i] = A[start+i];
    }
    for (j=0; j<sizeM; j++) {
        M[j] = A[mid+j+1];
    }
    i = 0;
    j = 0;
    k = start;
    /* Sort the sub-arrays while merging back to A[] */
    while ((i < sizeL) && (j < sizeM)) {
        if (L[i] < M[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = M[j];
            j++;
        }
        k++;
    }
    /* If M[] exhausted, put remaining L[] back */
    while (i < sizeL) {
        A[k] = L[i];
        i++;
        k++;
    }
    /* If L[] exhausted, put remaining M[] back */
    while (j < sizeM) {
        A[k] = M[j];
        j++;
        k++;
    }
}

void sort(int A[], int start, int end) {
    /* Base case is a single element array i.e already sorted */
    if (start < end) {
        int mid = (start + end)/2;
        /* Divide and conquer ;) */
        sort(A, start, mid);
        sort(A, mid+1, end);
        merge(A, start, mid, end);
    }
}

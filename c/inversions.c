#include <stdio.h>
#include <stdlib.h>

#define LLI long long int

LLI inversions = 0;

void countSplitInv(LLI [], LLI, LLI, LLI);
void countInv(LLI[], LLI, LLI);
 
int main() {
    LLI i, size, j, T;
    LLI * A;
    scanf("%lld", &T);
    for (j=0; j<T; j++) {
        scanf("%lld", &size);
        A = malloc(size * sizeof(LLI));
        for (i=0; i<size; i++) {
            scanf("%lld", &A[i]);
        }
        inversions = 0;
        countInv(A, 0, size-1);
        printf("%lld\n", inversions);
        free(A);
    }
    return 0;
}

void countSplitInv(LLI A[], LLI start, LLI mid, LLI end) {
    LLI sizeL = mid - start + 1;
    LLI sizeM = end - mid;
    LLI L[sizeL], M[sizeM];
    LLI i, j, k;
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
            /* inversions += number of elements remaining in L */ 
            inversions += sizeL - i;
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

void countInv(LLI A[], LLI start, LLI end) {
    /* Base case is a single element array i.e already sorted */
    if (start < end) {
        LLI mid = (start + end)/2;
        /* Divide and conquer ;) */
        countInv(A, start, mid);
        countInv(A, mid+1, end);
        countSplitInv(A, start, mid, end);
    }
}

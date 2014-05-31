#include <stdio.h>

void merge(int [], int, int, int);
void sort(int[], int, int);
 
int main() {
    int i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, 0, n-1);
    printf("\nSORTED ARRAY IS: \n");
    for (i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

void merge(int A[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1], M[n2];
    int i, j, k;
    /* Split the array A[] into L[p to q] and M[q+1 to r] */
    for (i=0; i<n1; i++) {
        L[i] = A[p+i];
    }
    for (j=0; j<n2; j++) {
        M[j] = A[q+j+1];
    }
    i=0;
    j=0;
    k=p;
    /* Merge the two arrays back into A[], until one of them exhausts */
    while (i<n1 && j<n2) {
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
    while (i<n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    /* If L[] exhausted, put remaining M[] back */
    while (j<n2) {
        A[k] = M[j];
        j++;
        k++;
    }
}

void sort(int A[], int p, int r) {
    /* Base case is a single element array i.e already sorted */
    if (p < r) {
        int q = (p+r)/2;
        /* Divide and conquer ;) */
        sort(A, p, q);
        sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

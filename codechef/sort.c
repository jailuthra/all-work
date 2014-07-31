#include <stdio.h>
#include <stdlib.h>

long long int count = 0;

void sort(unsigned long int * A, unsigned long int n);

int main() {
    unsigned long int i, n;
    scanf("%lu", &n);
    unsigned long int A[n];
    for (i = 0; i < n; i++) {
        scanf("%lu", &A[i]);
    }
    sort(A, n);
    printf("%lld\n", count);
    return 0;
}

void sort(unsigned long int * A, unsigned long int n) {
    if (n <= 1) {
        return;
    }
    unsigned long int less[n];
    unsigned long int greater[n];
    unsigned long int pivot = A[((n+1)/2)-1];
    unsigned long int i, j = 0, k = 0;
    for (i = 0; i < n; i++) {
        count++;
        if (A[i] < pivot) {
            less[j++] = A[i];
        } else if (A[i] > pivot) {
            greater[k++] = A[i];
        }
    }
    sort(less, j);
    sort(greater, k);
}

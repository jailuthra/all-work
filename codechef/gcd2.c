#include<stdio.h>

#define ULLI unsigned long long int

int main() {
    ULLI n, i, a, b, swap, gcd;
    scanf("%llu", &n);
    for (i = 0; i < n; i++) {
        scanf("%llu %llu", &b, &a);
        while (1) {
            if (b == 0) {
                gcd = a;
                break;
            }
            else {
                swap = a;
                a = b;
                b = swap % b;
            }
        }
        printf("%llu\n", gcd);
    }
    return 0;
}

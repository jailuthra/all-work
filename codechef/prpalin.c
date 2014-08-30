#include<stdio.h>

#define LLI long long int

int main() {
    scanf("%llu", &n);
    if (n%2==0 && n!=2) {
        n++;
    }
    i = n;
    while (1) {
        if (palindrome(i)) {
            if (prime(i)) {
                break;
            }
        }
        i++;
    }

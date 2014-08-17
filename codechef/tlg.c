#include <stdio.h>

int main() {
    int i, n, sum_a, sum_b, a, b, lead, max_lead=0, winner;
    scanf("%d", &n);
    sum_a = 0;
    sum_b = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        sum_a += a;
        sum_b += b;
        lead = sum_a - sum_b;
        if (lead > 0) {
            if (lead > max_lead) {
                max_lead = lead;
                winner = 1;
            }
        } else {
            if (-lead > max_lead) {
                max_lead = -lead;
                winner = 2;
            }
        }
    }
    printf("%d %d\n", winner, max_lead);
    return 0;
}

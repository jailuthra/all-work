#include <stdio.h>

int main() {
    int t, i, j, holes;
    char arr[40][100];
    scanf("%d", &t);
    for (i=0; i<t; i++) {
        scanf("%s", arr[i]);
        holes = 0;
        for (j=0; arr[i][j]; j++) {
            switch (arr[i][j]) {
            case 'A': case 'D': case 'O': case 'P': case 'R': case 'Q':
                holes++;
                break;
            case 'B':
                holes += 2;
                break;
            default:
                break;
            }
        }
        printf("%d\n", holes);
    }
    return 0;
}

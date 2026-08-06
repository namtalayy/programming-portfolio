#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j > 1) printf(" ");
            if (i == 1 || i == n || j == 1 || j == i) {
                printf("0");
            } else {
                printf("3");
            }
        }
        printf("\n");
    }

    return 0;
}
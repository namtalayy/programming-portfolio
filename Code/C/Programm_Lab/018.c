#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    int found = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            if (found) printf(" ");
            printf("%d", i);
            count++;
            found = 1;
        }
    }

    if (count == 0) {
        printf("null");
    }

    printf("\n%d\n", count);

    return 0;
}
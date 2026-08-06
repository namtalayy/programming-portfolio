#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0 0\n");
        return 0;
    }

    char stations[100][20];
    for (int i = 0; i < n; i++) {
        scanf("%s", stations[i]);
    }

    int before = 16, lines = 1;

    for (int i = 1; i < n; i++) {
        if (stations[i][0] == stations[i-1][0]) {
            before += 3;
        } else {
            before += 16;
            lines++;
        }
    }

    printf("%d %d\n", before, lines * 20);

    return 0;
}
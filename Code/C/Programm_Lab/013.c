#include <stdio.h>

int main() {
    int n;
    (void)scanf("%d", &n);

    int total = 0;
    int seats[100];

    for (int i = 0; i < n; i++) {
        int votes;
        (void)scanf("%d", &votes);
        if (votes >= 50) {
            seats[i] = votes / 10;
        } else {
            seats[i] = 0;
        }
        total += seats[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", seats[i]);
    }

    printf("%d\n", total);

    if (total >= 50) {
        printf("Success\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}
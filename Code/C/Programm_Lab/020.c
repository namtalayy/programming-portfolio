#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            sum += x;
            count++;
        }
    }

    if (count == 0) {
        printf("No Even\n");
    } else {
        printf("%d\n", sum);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int amount;
    scanf("%d", &amount);

    if (amount < 0 || amount % 100 != 0) {
        printf("Invalid amount\n");
        return 0;
    }

    int original = amount;
    int b1000 = amount / 1000;
    amount %= 1000;

    int b500 = amount / 500;
    amount %= 500;

    int b100 = amount / 100;

    printf("1000: %d\n", b1000);
    printf("500: %d\n", b500);
    printf("100: %d\n", b100);

    return 0;
}
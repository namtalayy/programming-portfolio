#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("null\n");
        return 0;
    }

    int t[30];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        if (t[i] < 1 || t[i] > 30) {
            printf("null\n");
            return 0;
        }
    }

    // คนมาทีหลัง (index สูง) นั่งหน้า → reverse แล้วพิมพ์ทีละ 3
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", t[i]);
        if (i % 3 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }

    return 0;
}
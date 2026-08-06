#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);

    int minV[10], maxV[10];
    for (int i = 0; i < m; i++) {
        char dot;
        scanf("%d%c%d", &minV[i], &dot, &maxV[i]);
    }

    int count = 0;

    for (int start = minV[0]; start <= maxV[0]; start++) {
        int valid = 1;
        for (int i = 0; i < m; i++) {
            int val = start + i;
            if (val < minV[i] || val > maxV[i]) {
                valid = 0;
                break;
            }
        }
        if (valid) count++;
    }

    printf("%d\n", count);

    return 0;
}
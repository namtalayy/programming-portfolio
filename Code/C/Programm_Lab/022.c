#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int h[100];
    int maxH = 0;
    int totalW = 0;

    for (int i = 0; i < n; i++) {
        do {
            scanf("%d", &h[i]);
        } while (h[i] <= 0);
        if (h[i] > maxH) maxH = h[i];
        totalW += h[i] * 2;
    }

    char canvas[200][500];
    for (int r = 0; r < maxH; r++) {
        memset(canvas[r], ' ', totalW);
        canvas[r][totalW] = '\0';
    }

    int col = 0;
    for (int i = 0; i < n; i++) {
        for (int row = 1; row <= h[i]; row++) {
            int r = (maxH - h[i]) + (row - 1);
            int leftSpace = h[i] - row;
            int slashCol = col + leftSpace;
            int backslashCol = slashCol + 1 + (row - 1) * 2;
            canvas[r][slashCol] = '/';
            canvas[r][backslashCol] = '\\';
        }
        col += h[i] * 2;
    }

    for (int r = 0; r < maxH; r++) {
        int len = totalW;
        while (len > 0 && canvas[r][len-1] == ' ') len--;
        canvas[r][len] = '\0';
        printf("%s\n", canvas[r]);
    }

    return 0;
}
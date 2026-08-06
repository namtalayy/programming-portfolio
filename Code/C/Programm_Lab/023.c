#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    double total = 0;

    for (int i = 0; i < n; i++) {
        int kills, assists;
        char mvp[3];
        scanf("%d %d %s", &kills, &assists, mvp);

        double score = kills * 3 + assists;

        if (mvp[0] == 'Y' || mvp[0] == 'y') {
            score += score * 0.05;
        }

        total += score;
    }

    double avg = total / n;
    double rounded = floor(avg * 100 + 0.5) / 100;
    printf("%.2f\n", rounded);

    return 0;
}
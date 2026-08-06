#include <stdio.h>

int main() {
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);

    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
        printf("Invalid\n");
        return 0;
    }

    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if (m < 3) y--;

    int w = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;

    printf("%s\n", days[w]);

    return 0;
}
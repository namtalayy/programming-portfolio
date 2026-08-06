#include <stdio.h>
int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) printf("*");
    printf("\n");

    if (n - 2 >= 1) {
        for (int i = 0; i < n - 2; i++) printf("*");
    }
    printf("\n");

    if (n - 4 >= 1) {
        for (int i = 0; i < n - 4; i++) printf("*");
    }
    printf("\n");

    return 0;
}
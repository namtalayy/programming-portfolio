#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    scanf("%s", s);

    // เลขติดลบไม่ใช่ palindrome
    if (s[0] == '-') {
        printf("no\n");
        return 0;
    }

    int len = strlen(s);
    int isPalin = 1;

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }

    printf("%s\n", isPalin ? "yes" : "no");

    return 0;
}
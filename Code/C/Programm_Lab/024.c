#include <stdio.h>
#include <string.h>

int main() {
    char s[205];
    scanf("%s", s);
    int len = strlen(s);

    char rev[205];
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    rev[len] = '\0';

    printf("%s %s\n", s, rev);

    // นับใน original เท่านั้น
    int count[256] = {0};
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
    }

    int printed[256] = {0};
    for (int i = 0; i < len; i++) {
        unsigned char c = s[i];
        if (count[c] > 1 && !printed[c]) {
            printf("%c%d\n", c, count[c]);
            printed[c] = 1;
        }
    }

    return 0;
}
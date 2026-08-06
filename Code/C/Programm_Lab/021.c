#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    while (t--) {
        char line[205];
        fgets(line, sizeof(line), stdin);

        char stack[205];
        int top = 0;
        int balanced = 1;

        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];
            if (c == '(' || c == '{' || c == '[') {
                stack[top++] = c;
            } else if (c == ')' || c == '}' || c == ']') {
                if (top == 0) {
                    balanced = 0;
                    break;
                }
                char open = stack[--top];
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '[')) {
                    balanced = 0;
                    break;
                }
            }
        }

        if (top != 0) balanced = 0;

        printf("%s\n", balanced ? "YES" : "NO");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int c, prev = 0;
    int in_string = 0, in_char = 0;
    int in_single_comment = 0, in_multi_comment = 0;

    while ((c = getchar()) != EOF) {

        
        if (in_single_comment) {
            if (c == '\n') {
                in_single_comment = 0;
                putchar('\n');
            }
            continue;
        }

       
        if (in_multi_comment) {
            if (prev == '*' && c == '/')
                in_multi_comment = 0;
            prev = c;
            continue;
        }

       
        if (in_string) {
            putchar(c);
            if (c == '\\') {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            } else if (c == '"') {
                in_string = 0;
            }
            continue;
        }

       
        if (in_char) {
            putchar(c);
            if (c == '\\') {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            } else if (c == '\'') {
                in_char = 0;
            }
            continue;
        }

        
        if (c == '"') {
            in_string = 1;
            putchar(c);
            continue;
        }

        if (c == '\'') {
            in_char = 1;
            putchar(c);
            continue;
        }

        if (c == '/') {
            int next = getchar();

            if (next == '/') {
                in_single_comment = 1;
            } else if (next == '*') {
                in_multi_comment = 1;
                prev = 0;
            } else {
                putchar(c);
                if (next != EOF)
                    putchar(next);
            }
            continue;
        }

        putchar(c);
    }

    return 0;
}
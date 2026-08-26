#include <stdio.h>
#include <stdlib.h>

int main() {
    char expression[50];
    int stack[50];
    int top = -1;

    // Read the postfix expression token by token
    while (scanf("%49s", expression) == 1) {

        // If token is a number
        if (expression[0] >= '0' && expression[0] <= '9') {
            stack[++top] = atoi(expression);
        }
        else {
            int b = stack[top--];
            int a = stack[top--];

            switch (expression[0]) {
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;
            }
        }
    }

    printf("%d\n", stack[top]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for performing operations
int operations(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Error: Invalid expression\n");
            exit(1);
    }
}


int isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to evaluate the expression
int evaluate(const char *expression) {
    int number_stack[1000], number_top = -1; 
    char operator_stack[1000], operator_top = -1; 

    int i = 0;
    int num = 0;
    int is_number = 0;

    while (expression[i] != '\0') {
        char ch = expression[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            is_number = 1;
        } else if (ch == ' ') {
            
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (is_number) {
                number_stack[++number_top] = num;
                num = 0;
                is_number = 0;
            }

           while (operator_top != -1 && precedence(operator_stack[operator_top]) >= precedence(ch)) {
                int b = number_stack[number_top--];
                int a = number_stack[number_top--];
                char op = operator_stack[operator_top--];
                number_stack[++number_top] = operations(a, b, op);
            }

            operator_stack[++operator_top] = ch;
        } else {
            printf("Error: Invalid expression.\n");
            exit(1);
        }

        i++;
}

    if (is_number) {
        number_stack[++number_top] = num;
    }

    while (operator_top != -1) {
        int b = number_stack[number_top--];
        int a = number_stack[number_top--];
        char op = operator_stack[operator_top--];
        number_stack[++number_top] = operations(a, b, op);
    }
    
    
    return number_stack[number_top];
}

int main() {
    char expression[2000];

    printf("Input: ");
   scanf("%[^\n]", expression);

    int len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluate(expression);
    printf("Output: %d\n", result);

    return 0;
}










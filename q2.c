#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX];
    
    printf("Enter an expression: ");
    scanf("%s", expr);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("Not Balanced Expression\n");
                return 0;
            }
            char popped = pop();
            if (!isMatchingPair(popped, ch)) {
                printf("Not Balanced Expression\n");
                return 0;
            }
        }
    }

    // If stack is empty → balanced
    if (top == -1) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }

    return 0;
}
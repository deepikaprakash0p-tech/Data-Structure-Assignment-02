#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
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
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters into stack
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop characters to reverse string
    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
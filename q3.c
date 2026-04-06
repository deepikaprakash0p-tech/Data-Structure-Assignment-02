#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start from first element
    push(arr[0]);

    for (int i = 1; i < n; i++) {
        int next = arr[i];

        // Compare with stack elements
        while (!isEmpty() && stack[top] < next) {
            printf("%d -> %d\n", pop(), next);
        }

        push(next);
    }

    // Remaining elements have no greater element
    while (!isEmpty()) {
        printf("%d -> -1\n", pop());
    }

    return 0;
}
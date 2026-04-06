#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

// Enqueue (Add document)
void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow (Printer queue full)\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        strcpy(queue[rear], doc);
        printf("Document added: %s\n", doc);
    }
}

// Dequeue (Print document)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow (No documents to print)\n");
    } else {
        printf("Printing document: %s\n", queue[front]);
        front++;
    }
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents\n");
    } else {
        printf("Pending documents:\n");
        for (int i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

int main() {
    int choice;
    char doc[50];

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Pending Documents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
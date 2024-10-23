#include <stdio.h>

#define N 5
int q[N];
int front = -1, rear = -1;

void push(int item) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) { // Empty queue
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }
        q[rear] = item;
    }
}

void pop() {
    if (front == -1) { // Queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Popped item: %d\n", q[front]);
        if (front == rear) { // Queue has only one element
            front = rear = -1; // Reset to empty
        } else {
            front = (front + 1) % N;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", q[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", q[rear]); // Print the last element
    }
}

int main() {
    int item, choice;
   
    while (1) {
        printf("Enter choice (1: Push, 2: Pop, 3: Display, 0: Exit): ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                return 0; // Exit the program
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}


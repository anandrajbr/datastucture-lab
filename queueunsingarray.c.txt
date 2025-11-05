#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if ((rear + 1) % N == front) {
        printf("Queue is Overflow!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow!\n");
    } else if (front == rear) {
        printf("Deleted item is: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted item is: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[rear]);
}

void search() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow!\n");
        return;
    }

    int data, pos = 1, i = front, found = 0;
    printf("Enter the data to search: ");
    scanf("%d", &data);

    while (1) {
        if (queue[i] == data) {
            found = 1;
            break;
        }
        if (i == rear)
            break;
        i = (i + 1) % N;
        pos++;
    }

    if (found)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found in the queue\n");
}

int main() {
    int opt;
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    } while (1);

    return 0;
}

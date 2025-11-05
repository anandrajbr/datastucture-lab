#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void push() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("\n%d is pushed into the stack\n", head->data);
}

void pop() {
    struct node *temp;
    if (head == NULL) {
        printf("\nStack is empty\n");
    } else {
        temp = head;
        printf("The deleted data is %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}

void peek() {
    if (head == NULL) {
        printf("\nStack is empty\n");
    } else {
        printf("Top element is %d\n", head->data);
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nStack is empty\n");
    } else {
        temp = head;
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int opt;
    do {
        printf("\n1) PUSH\n");
        printf("2) POP\n");
        printf("3) PEEK\n");
        printf("4) DISPLAY\n");
        printf("5) QUIT\n");
        printf("Choose your option: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    } while (1);
}

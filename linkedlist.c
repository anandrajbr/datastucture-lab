#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void delete() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

void search() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int data, pos = 1, flag = 0;
    struct node *temp = head;

    printf("Enter the data to search: ");
    scanf("%d", &data);

    while (temp != NULL) {
        if (temp->data == data) {
            flag = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (flag)
        printf("Data %d found at position %d\n", data, pos);
    else
        printf("Data %d not found in the list\n", data);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int opt;
    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    } while (opt != 5);

    return 0;
}

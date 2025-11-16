#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* root = NULL;

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

struct node* findMin(struct node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void freeTree(struct node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    int opt, data;
    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder)\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter option: ");

        if (scanf("%d", &opt) != 1) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            break;
        }

        switch (opt) {
            case 1:
                printf("Enter the data to insert: ");
                if (scanf("%d", &data) != 1) { fprintf(stderr, "Invalid input.\n"); break; }
                root = insert(root, data);
                printf("Value %d inserted into the BST.\n", data);
                break;

            case 2:
                printf("Enter the data to delete: ");
                if (scanf("%d", &data) != 1) { fprintf(stderr, "Invalid input.\n"); break; }
                if (search(root, data) == NULL) {
                    printf("Value %d not found in the BST.\n", data);
                } else {
                    root = deleteNode(root, data);
                    printf("Value %d deleted from the BST (if it existed).\n", data);
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                if (root == NULL) printf("(empty)");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter the element to search: ");
                if (scanf("%d", &data) != 1) { fprintf(stderr, "Invalid input.\n"); break; }
                if (search(root, data)) {
                    printf("Value %d is present in the BST.\n", data);
                } else {
                    printf("Value %d not found in the BST.\n", data);
                }
                break;

            case 5:
                freeTree(root);
                printf("Exiting. Memory freed.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    freeTree(root);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure for the Binary Search Tree (BST)
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the tree using different traversal methods
void display(struct node* root, int choice) {
    switch (choice) {
        case 1:
            printf("\nIn-order traversal: ");
            inorder(root);
            break;
        case 2:
            printf("\nPre-order traversal: ");
            preorder(root);
            break;
        case 3:
            printf("\nPost-order traversal: ");
            postorder(root);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }
}

// Main function to take input and test the BST implementation
int main() {
    struct node* root = NULL;
    int n, data, choice;

    // Take input from the user for the number of nodes
    printf("Enter the number of nodes to insert in the BST: ");
    scanf("%d", &n);

    // Take input for each node and insert it into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    // Loop to repeatedly ask for traversal type
    while (1) {
        // Ask the user which traversal to display
        printf("\nChoose the type of traversal:\n");
        printf("1. In-order\n");
        printf("2. Pre-order\n");
        printf("3. Post-order\n");
        printf("4. Exit\n");  // Option to exit the loop
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program...\n");
            break;  // Exit the loop if user chooses 4
        }

        // Display the tree using the selected traversal
        display(root, choice);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node* NODE;

NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    }
    return ptr;
}

NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node; // Corrected: return new_node, not new_NEW
}

NODE insert_end(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = NULL;
    if (first == NULL) {
        return new_node;
    }
    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return first;
}

NODE insert_pos(NODE first, int item, int pos) {
    NODE new_node = get_node();
    new_node->value = item;

    if (pos == 1) {
        new_node->next = first;
        return new_node; // Corrected: Insert at the beginning
    }

    NODE current = first;
    int count = 1;
    NODE prev = NULL;

    while (count < pos && current != NULL) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL && count < pos) {
        printf("Invalid position\n");
        free(new_node); // Free the node if position is invalid
        return first;
    }

    prev->next = new_node;
    new_node->next = current;

    return first;
}

void display(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE head = NULL;
    int choice, item, pos;

    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                head = insert_beginning(head, item);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &item);
                head = insert_end(head, item);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &item, &pos);
                head = insert_pos(head, item, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


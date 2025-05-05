#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Top of the stack

// Push operation
void push() {

    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack underflow! Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("%d popped from stack.\n", temp->data);
    free(temp);
}

// Display stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
               
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
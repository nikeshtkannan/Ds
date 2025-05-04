#include <stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE], front = -1, rear = -1, choice = 0;

// Function Prototypes


void main() {
    while (choice != 4) {   
        printf("\nChoose one of the below:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid choice! Please enter between 1-4.\n");
        }
    } 
}

// Insert Function
void insert() {
    int val;
    if (rear == MAXSIZE - 1) {
        printf("Queue Overflow (Full)\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &val);
        if (front == -1 && rear == -1) {   // First element
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = val;
        printf("Value inserted into the queue.\n");
    }
}

// Delete Function
void delete() {
    int val;
    if (front == -1 && rear == -1) {
        printf("Queue Underflow (Empty)\n");
    } else {
        val = queue[front];   // Remove front value
        if (front == rear) {  // Only one element left
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        printf("Deleted value: %d\n", val);
    }
}

// Display Function
void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element
void enqueue() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue Overflow (Full)\n");
    } else {
        printf("Enter a value:");
        scanf("%d",&value);
        if (front == -1) {  // First element
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {  // Wrap around
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}

// Delete element
void dequeue() {
    int value;
    if (front == -1) {
        printf("Queue Underflow (Empty)\n");
    } else {
        value=queue[front];
        if (front == rear) {  // Only one element left
            front = rear = -1;
        } else if (front == MAX - 1) {  // Wrap around
            front = 0;
        } else {
            front++;
        }
        printf("Deleted element: %d\n",value);
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        } else {
            for (int i = front; i < MAX; i++)
                printf("%d ", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
    while (choice!=4) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

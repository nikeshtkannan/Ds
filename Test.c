#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void enqueue(){
    int val;
    if((front==0 && rear==MAX-1) || (rear+1==front)){
        printf("OVERFLOW\n");
    }
    else{
        printf("Enter the value");
        scanf("%d",&val);
        if(front==-1 && rear==-1){
            front=rear=0;
        }
        else if(rear==MAX+1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=val;
        printf("%d entered",val);
    }
}

void dequeue(){
    int val;
    if(front==-1){
        printf("underflow\n");
    }
    else{
        val=queue[front];
        
        if(front==rear){
            front=rear=-1;
        }
        else if(front==MAX-1){
            front=0;
        }
        else{
            front++;
        }
        printf("%d removed\n",val);
    }
}

void display(){
    int i;
    if(front==-1){
        printf("underflow\n");
    }
    else{
        printf("Elements:");
        if(rear>=front){
            for(i=front;i<=rear;i++)
                printf("%d",queue[i]);
        }
        else{
            for(i=front;i<MAX;i++)
                printf("%d",queue[i]);
            for(i=0;i<=rear;i++)
                printf("%d",queue[i]);
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


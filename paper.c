#include <stdio.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;

void enqueue(){
    int val;
    if((front==0 && rear==MAX-1)||(rear+1==front)){
        printf("Overflow");
    }
    else{
        printf("Enter the value:");
        scanf("%d",&val);
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else if(front!=0 && rear+1==front){
            rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=val;
    }
}
void dequeue(){
    int val;
    if(front==-1){
        printf("Underflow");
    }
    else{
        val=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==MAX-1){
            front=0;
        }
        else{
            front++;
        }

    }
    printf("popped:%d",val);
}
void display(){
    if(rear==-1){
        printf("Underflow");
    }
    else{
        if(rear>front){
            for(int i=front;i<=rear;i++)
                printf("%d",queue[i]);
        }
        else{
            for(int i=front;i<=MAX-1;i++)
                printf("%d",queue[i]);
            for(int i=0;i<=rear;i++)
                printf("%d",queue[i]);
        }
    }

}


int main(){
    int choice;
    while (choice!=4)
    {   
        printf("Choose one of the below");
        printf("\n1, Enqueue \n2,Dequeue \n3,Show \n4,Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
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
            printf("Exiting....");
            break;
        default:
            printf("Invalid Entering!!!");
            break;
        }
    } 
    return 0;
}
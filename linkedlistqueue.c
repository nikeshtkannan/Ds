#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(){
    int val;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Overflow");
        return;
    }
    printf("Enter the value:");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("entered %d",newnode->data);
}
void dequeue(){
    struct node* temp;
    if(front==NULL && rear==NULL){
        printf("Underflow");
        return;
    }
    temp=front;
    printf("%d",front->data);
    if(front==rear){
        front=NULL;
        rear=NULL;
    }
    else{
        front=front->next; 
    }
    free(temp);

}
void display(){
    if(front==NULL && rear==NULL){
        printf("underflow");
    }
    else{
        struct node* temp=front;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }

    }
}


void main(){
    int choice;
    while (choice!=4)
    {   
        printf("Choose one of the below");
        printf("\n1, push \n2,pop \n3,Show \n4,Exit\n");
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
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insertAtBeginning(){
    int val;
    printf("Enter value:");
    scanf("%d",&val);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at beginning.");
}
void insertAtEnd(){
    int val;
    printf("Enter value:");
    scanf("%d",&val);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("inserted %d at end",val);
}

void insertAtPos(){
    int val,position;
    printf("Enter value:");
    scanf("%d",&val);
    printf("Enter pos:");
    scanf("%d",&position);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(position==1){
        newNode->next=head;
        head=newNode;
        return;
    }
    struct Node* temp=head;
    for(int i=1;i<position-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("no space");
        free(newNode);
    }
    else{
        newNode->next=temp->next;
        temp->next=newNode;
        
    }
}


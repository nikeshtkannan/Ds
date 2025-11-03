#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}
struct node* head=NULL;

void insertAtBeginning(){
    int val;
    printf("Enter the value:");
    scanf("%d",&val);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("%d entered",newnode->data);
}
void insertAtEnd(){
    int val;
    printf("Enter the value:");
    scanf("%d",&val);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("%d Entered",newnode->data);
}
void insertAtPosition(){
    int val,pos;
    printf("Enter the val");
    scanf("%d",&val);
    printf("Enter the  pos:");
    scanf("%d",&pos);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    for(int i=1;i<pos-1 || temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("invalid");
        return;
    }
    temp->next=newnode;
    printf("%d entered",newnode->data);
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("Empty");
        return;
    }
    struct node* temp=head;
    printf("%d deleted",temp->data);
    head=head->next;
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("empty");
        return;
    }
    if(head->next==NULL){
        printf("%d deleted",head->data);
        free(head);
        head==NULL;
    }
    struct node* temp=head;
    while(temp->next->next->!=NULL){
        temp=temp->next;
    }
    
}


int main() {
    int choice;
    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
             
                insertAtBeginning();
                break;
            case 2:
                
                insertAtEnd();
                break;
            case 3:
              
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
             
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

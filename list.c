#include <stdio.h>
#include<stdlib.h>// to add dyanamic memory allocation
int value,choice;
struct node
{
    int data ;
    struct node* link;
};
struct node *head=NULL;
void insert_pos()
{
    struct node *temp;
    struct node *temp1;
    int pos;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("underflow \n");
    else
    {
        temp1=head;
        int count=1;
        printf("\nEnter the position to insert: ");
        scanf("%d", &pos);
        while(count<pos-1)
        {
            temp1 = temp1->link;
            count++;
        }
        printf("\nenter element to be inserted:\n");
        scanf("%d",&value);
        temp->link = temp1->link;
        temp1->link = temp;
        temp->data = value;
        printf("\n  inserted successfully \n");
    }
}

void insert_end()
{
    struct node *temp;
    struct node *temp1;
    temp=(struct node*)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("underflow \n");
    }
    else
    {
        temp1=head;
        while(temp1->link !=NULL)
        {
            temp1=temp1->link;

        }
        printf("\nenter element to be inserted:\n");
        scanf("%d",&value);
        temp1->link=temp;
        temp->data=value;
        temp->link=NULL;
        printf("\n  inserted successfully \n");
    }
}
void insert_begin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("underflow \n");
    }
    else
    {
        printf("\nenter element to be inserted:\n");
        scanf("%d",&value);
    
        temp->data =value;
        temp->link =head;
        head=temp;
        printf("\n element inserted ");
    }
}
void delete_begin()
{
    struct node* temp;
    if (head == NULL)
    {
        printf("\n underflow \n");
    }
    else
    {
        temp = head;
        head = head -> link;
        free(temp);
        printf("\n deleted \n");
    }
}
void delete_end()
{
    struct node* temp,*temp1;
    if (head == NULL)
    {
       printf("\n underflow \n");
    }
    else
    {
       temp = head;
       while(temp->link !=NULL)
       {
           temp1 = temp;
           temp = temp->link;
       }
       temp1->link=NULL;
       free(temp);
       printf("\n deleted \n");
    }
}
void delete_pos()
{
    struct node* temp;
    struct node *temp1;
    int pos;
     if (head == NULL)
    {
       printf("\n underflow \n");
    }
    else
    {
        temp=head;
        int count=1;
        printf("\nEnter the position to delete: ");
        scanf("%d", &pos);
        while(pos-1>count)
        {
            temp=temp->link;
            count++;
        }
        temp1=temp->link;
        temp->link=temp->link->link;
        free(temp1);
        printf("\n deleted \n");
    }

}
void printlist()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}
void main()
{
    while(1)
    {
        printf("enter your choice \n 1.insert_begin \n 2.insert_end \n 3.insert_pos \n 4.delete_begin\n 5.delete_end\n 6.delete_pos\n ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case  6:
                delete_pos();
                break;
            default:
                printf("wrong choice !!!");
                break;
        }  
        printf("given linked list is : \n \n" );
        printlist(head);
    }
}
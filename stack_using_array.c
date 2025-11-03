#include <stdio.h>

int stack[100],i,choice=0,top=-1,n;
void main(){
    printf("Enter the limit:");
    scanf("%d",&n);
    while (choice!=4)
    {   
        printf("Choose one of the below");
        printf("\n1, push \n2,pop \n3,Show \n4,Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
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

void push(){
    int val;
    if (top==n-1)
    {
        printf("Overflow\n");
    }
    else{
        printf("Enter the value:");
        scanf("%d",&val);
        top++;
        stack[top]=val;
    }
}
void pop(){
    int val;
    if (top==-1)
    {
        printf("Underflow\n");
    }
    else{
        val=stack[top];
        top--;
    }
}
void show(){
    if (top==-1)
    {
        printf("Underflow\n");
    }
    else{
        for ( i = top; i >=0; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
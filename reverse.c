#include <stdio.h>
#include <string.h>

void push(char);
char pop();
int top=-1;
char stack[20];

void push(char c){
    top++;
    stack[top]=c;
}
char pop(){
    char c;
    c=stack[top];
    top--;
    return c;
}

void main(){
    char str[20];
    int i,l,ch;
    printf("Enter a string: ");
    gets(str);
    l=strlen(str);
    for(i=0;i<l;i++){
        push(str[i]);
    }
    printf("reversed:");
    for(i=0;i<l;i++){
        ch=pop();
        printf("%c",ch);
    }
}
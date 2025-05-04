#include <stdio.h>
#include <string.h>
#define MAX 50

char infix[MAX];
char postfix[MAX];
char stack[MAX];

int top=-1;
void push(char);
char pop();
int precedence(char);
void infixtopostfix();
int is_empty();
void print();

int main(){
    printf("Enter the infix:");
    gets(infix);
    infixtopostfix();
    print();
    return 0;
}

void infixtopostfix(){
    int i,j=0;
    char next,symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='('){
                    postfix[j++]=next;
                }
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while(!is_empty() && precedence(stack[top])>=precedence(symbol)){
                    postfix[j++]=stack[top];
                    pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
                break;
        }
    }
    while(!is_empty()){
        postfix[j++]=stack[top];
        pop();
    }
    postfix[j]='\0';

}

int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return -1;
            break;
    }   
}

int is_empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char symbol){
    if (top==MAX-1)
    {
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=symbol;
    }
}

char pop(){
    char symbol;
    if (top==-1)
    {
        printf("Underflow");
    }
    else{
        symbol=stack[top];
        top--;
    }
    return symbol;
    
}

void print(){
    int j=0;
    while (postfix[j])
    {
        printf("%c",postfix[j]);
        j++;
    }
    
}



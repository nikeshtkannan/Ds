#include<stdio.h>
#include<string.h>
# define MAX 50
char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;
void infixToPostfix();
char pop();
void push(char);
int precedence(char);
int isEmpty();
void print();
int main()
{
    printf("Enter the infix expression: ");
    gets(infix);

    infixToPostfix();
    print();
    return 0;

}
void infixToPostfix()
{
    char symbol,next;
    int i,j=0;
    for(i=0; i<strlen(infix); i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
            case '(':
                    push(symbol);
                    break;
            case ')':
                    while((next=pop()) != '(')
                    {
                        postfix[j++] = next;

                    }
                    break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                    while(! isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    {
                        postfix[j++] = stack[top];
                        pop();
                    }
                    push(symbol);
                    break;
            default:
                    postfix[j++] = symbol;
                    break;
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = stack[top];
        pop();
    }
    postfix[j] = '/0';
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':
                return 3;
        case '*':
        case '/':
                return 2;
        case '+':
        case '-':
                return 1;
        default:
                return -1;
    }
}

void push(char symbol)
{
    if(top == MAX-1)
    {
        printf("/nOVERFLOW/n");
    }
    else
    {
        top++;
        stack[top] = symbol;
    }
}
char pop()
{
    char symbol;
    if(top == -1)
    {
        printf("/nUNDERFLOW/n");
        return '\0';
    }
    else
    {
        symbol = stack[top];
        top--;

    }
    return symbol;
}
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void print()
{
    int j=0;
    while(postfix[j])
    {
        printf("%c", postfix[j]);
        j++;
    }
    printf("\n");
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;

int valStack[MAX];
int valTop = -1;

// Function declarations
void infixToPostfix();
char pop();
void push(char);
int precedence(char);
int isEmpty();
void print();
void evaluatePostfix();

// ---- Main Function ----
int main() {
    printf("Enter the infix expression: ");
    gets(infix);  // for simplicity

    infixToPostfix();  // Convert infix → postfix
    print();           // Display postfix
    evaluatePostfix(); // Evaluate postfix
    return 0;
}

// ---- Convert Infix to Postfix ----
void infixToPostfix() {
    char symbol, next;
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
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
    while (!isEmpty()) {
        postfix[j++] = stack[top];
        pop();
    }
    postfix[j] = '\0';
}

// ---- Operator Precedence ----
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

// ---- Push (same as your version) ----
void push(char symbol) {
    if (top == MAX - 1)
        printf("\nOVERFLOW\n");
    else {
        top++;
        stack[top] = symbol;
    }
}

// ---- Pop (same as your version) ----
char pop() {
    char symbol;
    if (top == -1) {
        printf("\nUNDERFLOW\n");
        return '\0';
    } else {
        symbol = stack[top];
        top--;
    }
    return symbol;
}

// ---- Check if stack empty ----
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// ---- Print Postfix Expression ----
void print() {
    int j = 0;
    printf("Postfix Expression: ");
    while (postfix[j]) {
        printf("%c", postfix[j]);
        j++;
    }
    printf("\n");
}

// ---- Evaluation of Postfix Expression ----
void evaluatePostfix() {
    int i = 0, n1, n2, result;
    valTop = -1; // reset for evaluation

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) { // if operand
            valStack[++valTop] = postfix[i] - '0';
        } else { // operator
            n2 = valStack[valTop--];
            n1 = valStack[valTop--];
            switch (postfix[i]) {
                case '+': result = n1 + n2; break;
                case '-': result = n1 - n2; break;
                case '*': result = n1 * n2; break;
                case '/': result = n1 / n2; break;
                case '^': result = n1 ^ n2; break;
                default: result = 0;
            }
            valStack[++valTop] = result;
        }
        i++;
    }
    printf("Result of Expression: %d\n", valStack[valTop]);
}

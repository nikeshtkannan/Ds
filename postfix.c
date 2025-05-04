#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1;

// Push operation
void push(int x) {
    stack[++top] = x;
}

// Pop operation
int pop() {
    return stack[top--];
}

int main() {
    char exp[20];
    int i = 0, num, n1, n2, result;

    printf("Enter the postfix expression: ");
    scanf("%s", exp);  // Take postfix expression as input

    while (exp[i] != '\0') {  // Traverse until the end of expression
        if (isdigit(exp[i])) {    // If the character is a digit
            num = exp[i] - '0';   // Convert character to integer
            push(num);            // Push number onto the stack
        } else {                  // If it's an operator
            n2 = pop();           // Pop second operand
            n1 = pop();           // Pop first operand

            switch (exp[i]) {     // Perform operation based on operator
                case '+': result = n1 + n2; break;
                case '-': result = n1 - n2; break;
                case '*': result = n1 * n2; break;
                case '/': result = n1 / n2; break;
                default: 
                    printf("Invalid Operator!\n");
                    return -1;
            }
            push(result);         // Push the result back onto the stack
        }
        i++;  // Move to the next character
    }

    // Final result will be on top of the stack
    printf("The result of the expression is: %d\n", pop());

    return 0;
}

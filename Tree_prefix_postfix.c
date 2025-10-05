 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 // Define tree node
 typedef struct Node {
    char data;
    struct Node *left, *right;
 } Node;
 // Create new node
 Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
 }
 // Stack for tree nodes
 typedef struct Stack {
    Node* arr[100];
    int top;
 } Stack;
 void push(Stack* s, Node* node) {
    s->arr[++s->top] = node;
 }
 Node* pop(Stack* s) {
    return s->arr[s->top--];
 }
 // Build expression tree from postfix expression
 Node* buildTree(char postfix[]) {
    Stack s;
    s.top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (ch == ' ') continue; // skip spaces
        if (isalnum(ch)) { // operand
            push(&s, createNode(ch));
        } else { // operator
            Node* node = createNode(ch);
            node->right = pop(&s);
            node->left = pop(&s);
            push(&s, node);
        }
    }
    return pop(&s);
 }
 // Traversals
 void printPrefix(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        printPrefix(root->left);
}
    }
        printPrefix(root->right);
 void printPostfix(Node* root) {
    if (root != NULL) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
 }
 int main() {
    char postfix[100];
    printf("Enter a postfix expression (e.g., ab+c*): ");
    scanf("%s", postfix);
    Node* root = buildTree(postfix);
    printf("\nPrefix  : ");
    printPrefix(root);
    printf("\nPostfix : ");
    printPostfix(root);
    printf("\n");
    return 0;
 }
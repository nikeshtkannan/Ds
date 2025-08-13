#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term into polynomial in descending order, merging if exponent matches
void insertTermSorted(Node** head, int coeff, int exp) {
    if (coeff == 0) return;

    Node* curr = *head;
    Node* prev = NULL;

    // Insert at head if list empty or exp is bigger than head's exp
    if (curr == NULL || exp > curr->exp) {
        Node* newNode = createNode(coeff, exp);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to find the correct position or matching exponent
    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->exp == exp) {
        curr->coeff += coeff;
        if (curr->coeff == 0) {  // Remove node if coeff becomes 0
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
        }
    } else {
        Node* newNode = createNode(coeff, exp);
        prev->next = newNode;
        newNode->next = curr;
    }
}

// Print polynomial
void display(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" + ");
        printf("%dx^%d", temp->coeff, temp->exp);
        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials and return the sum polynomial
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        int coeff, exp;
        if (p1->exp > p2->exp) {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            coeff = p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
        } else {
            coeff = p1->coeff + p2->coeff;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (coeff == 0) continue;

        Node* newNode = createNode(coeff, exp);
        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (p1 != NULL) {
        Node* newNode = createNode(p1->coeff, p1->exp);
        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        p1 = p1->next;
    }

    while (p2 != NULL) {
        Node* newNode = createNode(p2->coeff, p2->exp);
        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        p2 = p2->next;
    }

    return result;
}

// Multiply two polynomials and return the product polynomial
Node* multiplyPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    for (Node* a = p1; a != NULL; a = a->next) {
        for (Node* b = p2; b != NULL; b = b->next) {
            int coeff = a->coeff * b->coeff;
            int exp = a->exp + b->exp;
            insertTermSorted(&result, coeff, exp);
        }
    }
    return result;
}

// Free memory of polynomial
void freePoly(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Example polynomials
    insertTermSorted(&poly1, 3, 3);
    insertTermSorted(&poly1, 2, 2);
    insertTermSorted(&poly1, 1, 0);

    insertTermSorted(&poly2, 4, 2);
    insertTermSorted(&poly2, 5, 1);
    insertTermSorted(&poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    Node* sum = addPoly(poly1, poly2);
    printf("Sum: ");
    display(sum);

    Node* product = multiplyPoly(poly1, poly2);
    printf("Product: ");
    display(product);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);
    freePoly(product);

    return 0;
}

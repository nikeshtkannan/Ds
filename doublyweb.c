#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node {
    char url[MAX];
    struct node* prev;
    struct node* next;
} node;

node* current = NULL;

void visitpage(char* url) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        node* temp = current->next;
        while (temp != NULL) {
            node* todelete = temp;
            temp = temp->next;
            free(todelete);
        }
        current->next = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

void goback() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Went back to: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}

void goforward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Went forward to: %s\n", current->url);
    } else {
        printf("No next page.\n");
    }
}

void displaycurrentpage() {
    if (current != NULL) {
        printf("Current page: %s\n", current->url);
    } else {
        printf("No page loaded.\n");
    }
}

void clearHistory() {
    while (current != NULL && current->prev != NULL) {
        current = current->prev;
    }
    node* temp = current;
    while (temp != NULL) {
        node* todelete = temp;
        temp = temp->next;
        free(todelete);
    }
    current = NULL;
    printf("History cleared.\n");
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("-----BROWSER NAVIGATION----------\n");
        printf("1. VISIT PAGE\n2. GO BACK\n3. GO FORWARD\n4. Display Current Page\n5. Clear History\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0';
                visitpage(url);
                break;
            case 2:
                goback();
                break;
            case 3:
                goforward();
                break;
            case 4:
                displaycurrentpage();
                break;
            case 5:
                clearHistory();
                break;
            case 6:
                clearHistory();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

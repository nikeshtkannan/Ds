 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 // Define node structure
 typedef struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
 } Node;
 // Create a new node
 Node* createNode(char word[], char meaning[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
 }
 // Insert into BST
 Node* insert(Node* root, char word[], char meaning[]) {
    if (root == NULL) return createNode(word, meaning);
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word '%s' already exists.\n", word);
    return root;
 }
 // Search for a word
 Node* search(Node* root, char word[]) {
    if (root == NULL || strcmp(root->word, word) == 0)
        return root;
    if (strcmp(word, root->word) < 0)
        return search(root->left, word);
    else
        return search(root->right, word);
 }
 // Inorder traversal (alphabetical order)
 void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
 }
 // Free memory
 void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
 }
 int main() {
    Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    while (1) {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert word\n");
        printf("2. Search word\n");
        printf("3. Display dictionary (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf(" %[^\n]", meaning); // read full line
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                {
                    Node* result = search(root, word);
                    if (result != NULL)
                        printf("Meaning of '%s': %s\n", result->word, result->meaning);
 
                    else
                        printf("Word not found in dictionary.\n");
                }
                break;
            case 3:
                printf("\nDictionary contents (Alphabetical):\n");
                inorder(root);
                break;
            case 4:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
 }
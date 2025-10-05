#include <stdio.h>
 #include <string.h>
 // Function to find and replace all occurrences
 void findAndReplace(char str[], char find[], char replace[]) {
    char result[1000];   // buffer for new string
    int i, j, k;
    int lenFind = strlen(find);
    int lenReplace = strlen(replace);
    int lenStr = strlen(str);
    i = 0; j = 0;
    while (i < lenStr) {
        // Check if substring matches "find"
        if (strncmp(&str[i], find, lenFind) == 0) {
            // Copy "replace" into result
            for (k = 0; k < lenReplace; k++) {
                result[j++] = replace[k];
            }
            i += lenFind; // skip over the "find" word
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0'; // null terminate
    printf("\nModified Text: %s\n", result);
 }
 int main() {
    char text[1000], find[100], replace[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline
    printf("Enter the word to find: ");
    scanf("%s", find);
    printf("Enter the word to replace with: ");
    scanf("%s", replace);
    findAndReplace(text, find, replace);
    return 0;
 }


















 /*Algorithm FindAndReplace
Input: text string, find word, replace word
Output: modified text string

1. Start
2. Read text
3. Read find
4. Read replace
5. Initialize result ← empty string
6. Set i ← 0, j ← 0
7. While i < length(text) do
      a. If substring(text, i, length(find)) = find then
            i ← i + length(find)
            Copy replace into result at position j
            j ← j + length(replace)
         Else
            result[j] ← text[i]
            i ← i + 1
            j ← j + 1
      EndIf
   EndWhile
8. Append null terminator to result
9. Print result
10. Stop*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkFormat(char *str) {
    int i = 0, atFound = 0, dotFound = 0;
    if (strlen(str) == 1) return 0;
    while (*(str + i) != '\0') {
        if (*(str + i) == '@') atFound = 1;
        if (*(str + i) == '.' && atFound == 1) dotFound = 1;
        i++;
    }
    return (atFound && dotFound) ? 1 : 0;
}

int main() {
    char *input;
    input = (char *)malloc(100 * sizeof(char));
    scanf("%s", input);
    input = (char *)realloc(input, strlen(input) * sizeof(char));
    input[strlen(input)] = '\0';
    if (checkFormat(input)) printf("\nValid Email");
    else printf("\nInvalid Email");
    free(input);
    return 0;
}

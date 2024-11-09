#include <stdio.h>
int main() {
    int numWords;
    int wordLength1 = 0, wordLength2 = 0;
    int i, j, k, l, index = 0;
    
    printf("Enter the number of words: ");
    scanf("%d", &numWords);
    char words[numWords][100];

    for(i = 0; i < numWords; i++) {
        printf("Enter the %d word: ", i + 1);
        scanf("%s", words[i]);
    }
    
    for(i = numWords - 1; i >= 0; i--) {
        if(words[i][0] != ' ') {
            wordLength1 = 0;
            while(words[i][wordLength1] != '\0') wordLength1++;
            printf("[%s", words[i]);

            for(j = i - 1; j >= 0; j--) {
                wordLength2 = 0;
                while(words[j][wordLength2] != '\0') wordLength2++;

                for(k = 0; words[i][k] != '\0'; k++) {
                    for(l = 0; words[j][l] != '\0'; l++) {
                        if(words[i][k] == words[j][l]) break;
                    }
                    if(words[j][l] == '\0') break;
                }

                if(words[i][k] == '\0' && wordLength1 == wordLength2) {
                    printf(",%s", words[j]);

                    while(words[j][index] != '\0') {
                        words[j][index] = ' ';
                        index++;
                    }
                    index = 0;
                }
            }
            printf("],");
        }
    }
    return 0;
}


#include <stdio.h>


void countLetters(char slogans[][50], int index);
void frequency(char slogans[][50], int index, int start, int end);

int main() {
    int numSlogans,i;
    printf("Enter number of slogans: ");
    scanf("%d", &numSlogans);
    getchar();  
    char slogans[numSlogans][50];


    for ( i = 0; i < numSlogans; i++) {
        printf("Slogan %d: ", i + 1);
        fgets(slogans[i], 50, stdin);
    }

    
    for ( i = 0; i < numSlogans; i++) {
        printf("\nFor slogan: %s", slogans[i]);
        countLetters(slogans, i);
    }

    return 0;
}


void countLetters(char slogans[][50], int index) {
    int spaceIndex = -1;
    int charIndex;

    
    for (charIndex = 0; slogans[index][charIndex] != '\0'; charIndex++) {
        if (slogans[index][charIndex] == ' ') {
            spaceIndex = charIndex;
        }
    }

    int lastCharIndex = charIndex - spaceIndex - 2;

    
    frequency(slogans, index, spaceIndex, lastCharIndex);
}

void frequency(char slogans[][50], int index, int start, int end) {
    int totalLength = start + end + 1;
    int fre[totalLength];
	int i,j;
    for ( i = 0; i < totalLength; i++) {
        fre[i] = 1;
    }

    for (i = 0; i < totalLength; i++) {
        for ( j = i + 1; j < totalLength; j++) {
            if (slogans[index][i] == slogans[index][j]) {
                fre[i]++;
                if (i < start && j < start) fre[i]--;
                if (i > end && j > end) fre[i]--;
                if (slogans[index][i] == slogans[index][j]) slogans[index][j] = '0';
            }
        }
        if (slogans[index][i] != '0') {
            printf("'%c': %d\n", slogans[index][i], fre[i]);
        }
    }
}


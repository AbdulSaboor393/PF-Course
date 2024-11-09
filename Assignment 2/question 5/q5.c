#include <stdio.h>

int main() {
    int numElements, values[numElements], maxValue = 0,index;
    printf("Enter size of array: ");
    scanf("%d", &numElements);


    for( index = 0; index < numElements; index++) {
        printf("Enter number %d: ", index + 1);
        scanf("%d", &values[index]);
        if(values[index] > maxValue) {
            maxValue = values[index]; 
        }
    }
	int starCount;
	printf("\nHorizontal Histogram:\n");
    for( index = 0; index < numElements; index++) {
        printf("Value %d: ", index + 1);
        for( starCount = 0; starCount < values[index]; starCount++) {
            printf("* ");
        }
        printf("\n");
    }
	int row,col;
    printf("Vertical Histogram:\n");
    for( row = 0; row < maxValue; row++) { 
        for( col = 0; col < numElements; col++) {  
            if(values[col] >= maxValue - row) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");

        if(row == maxValue - 1) {
            for( col = 0; col < numElements; col++) {
                printf("%d ", values[col]);
            }
        }
    }

    return 0;
}



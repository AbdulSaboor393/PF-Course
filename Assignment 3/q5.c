#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char value[100];
};

int main() {
    int running = 1;
    int numTypes, numEntries;
    printf("Enter the number of types: ");
    scanf("%d", &numTypes);
    printf("Enter the number of entries: ");
    scanf("%d", &numEntries);

    struct Data **records;
    records = (struct Data **)malloc(numTypes * sizeof(struct Data *));
    for (int i = 0; i < numTypes; i++) {
        *(records + i) = (struct Data *)malloc((numEntries + 1) * sizeof(struct Data));
    }

    for (int i = 0; i < numTypes; i++) {
        for (int j = 0; j < (numEntries + 1); j++) {
            if (j == 0) printf("Enter the name for type %d: ", i + 1);
            else printf("Enter entry %d: ", j);
            scanf("%s", (*(records + i) + j)->value);
        }
    }

    while (running) {
        int choice;
        system("cls");
        printf("Press any key to continue...\n");
        getchar();
        printf("\n1. Add New Type\n");
        printf("2. Update Type\n");
        printf("3. Remove Type\n");
        printf("4. Display All Types\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numTypes++;
                records = (struct Data **)realloc(records, numTypes * sizeof(struct Data *));
                records[numTypes - 1] = (struct Data *)malloc((numEntries + 1) * sizeof(struct Data));
                for (int i = 0; i < (numEntries + 1); i++) {
                    if (i == 0) printf("Enter the name for type %d: ", numTypes);
                    else printf("Enter entry %d: ", i);
                    scanf("%s", (*(records + numTypes - 1) + i)->value);
                }
                break;

            case 2:
                printf("Enter the index (0-%d) of the type to update: ", numTypes - 1);
                int updateIndex;
                scanf("%d", &updateIndex);
                for (int i = 0; i < (numEntries + 1); i++) {
                    if (i == 0) printf("Update name for type %d: ", updateIndex + 1);
                    else printf("Update entry %d: ", i);
                    scanf("%s", (*(records + updateIndex) + i)->value);
                }
                break;

            case 3:
                printf("Enter the index (0-%d) of the type to remove: ", numTypes - 1);
                int removeIndex;
                scanf("%d", &removeIndex);
                --numTypes;
                for (int i = removeIndex; i < numTypes; i++) {
                    for (int j = 0; j < (numEntries + 1); j++) {
                        strcpy((*(records + i) + j)->value, (*(records + i + 1) + j)->value);
                    }
                }
                records = (struct Data **)realloc(records, numTypes * sizeof(struct Data *));
                break;

            case 4:
                for (int i = 0; i < numTypes; i++) {
                    for (int j = 0; j < numEntries + 1; j++) {
                        if (j == 0) printf("\nType %d: %s\n", i + 1, (*(records + i))->value);
                        else printf("Entry %d: %s\n", j, (*(records + i) + j)->value);
                    }
                }
                break;

            case 5:
                running = 0;
                printf("\nProgram has ended.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    for (int i = 0; i < numTypes; i++) {
        free(records[i]);
    }
    free(records);

    return 0;
}

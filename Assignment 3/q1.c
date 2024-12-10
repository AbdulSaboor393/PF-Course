
#include <stdio.h>
#define SIZE 4

struct Worker {
    int code;
    char name[100];
    int yearJoined;
};

void inputDetails(struct Worker *data, int size);
void calculateTenure(struct Worker data[], int size);

int main() {
    struct Worker data[SIZE];
    inputDetails(data, SIZE);
    calculateTenure(data, SIZE);
    return 0;
}

void inputDetails(struct Worker *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter code for worker %d: ", i + 1);
        scanf("%d", &(data + i)->code);
        printf("Enter name for worker %d: ", i + 1);
        scanf("%s", (data + i)->name);
        printf("Enter year joined for worker %d: ", i + 1);
        scanf("%d", &(data + i)->yearJoined);
        printf("\n");
    }
}

void calculateTenure(struct Worker data[], int size) {
    int count = 0, currentYear;
    printf("Enter the current year: ");
    scanf("%d", &currentYear);
    printf("Workers with tenure greater than 3 years:\n===========================================\n");
    for (int i = 0; i < size; i++) {
        if (currentYear - data[i].yearJoined > 3) {
            printf("Worker %d: %d %s %d\n", i + 1, data[i].code, data[i].name, data[i].yearJoined);
            count++;
        }
    }
    printf("\nTotal workers with tenure greater than 3 years: %d\n", count);
}

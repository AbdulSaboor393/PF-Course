#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Worker {
    int *scores;
    int total_score;
};

void inputRatings(int **scores, int numWorkers, int numEvaluations);
void displayRatings(int **scores, int numWorkers, int numEvaluations);
int findTopWorker(int **scores, int numWorkers, int numEvaluations);
int findBestEvaluationPeriod(int **scores, int numWorkers, int numEvaluations);
int findLowestWorker(int **scores, int numWorkers, int numEvaluations);

int main() {
    struct Worker *workers;
    int numWorkers, numEvaluations;

    printf("Enter the number of workers: ");
    scanf("%d", &numWorkers);
    printf("Enter the total number of evaluations: ");
    scanf("%d", &numEvaluations);

    workers = (struct Worker *)malloc(sizeof(struct Worker) * numWorkers);
    for (int i = 0; i < numWorkers; i++) {
        workers[i].scores = (int *)malloc(sizeof(int) * numEvaluations);
    }

    int **scores = (int **)malloc(sizeof(int *) * numWorkers);
    for (int i = 0; i < numWorkers; i++) {
        *(scores + i) = workers[i].scores;
    }

    inputRatings(scores, numWorkers, numEvaluations);
    displayRatings(scores, numWorkers, numEvaluations);

    printf("\n\n\n==========================================\n");
    printf("%d Worker has the highest average", findTopWorker(scores, numWorkers, numEvaluations) + 1);
    printf("\n%d Period has the highest average", findBestEvaluationPeriod(scores, numWorkers, numEvaluations) + 1);
    printf("\nWorst-performing worker is %d", findLowestWorker(scores, numWorkers, numEvaluations) + 1);

    return 0;
}

void inputRatings(int **scores, int numWorkers, int numEvaluations) {
    for (int i = 0; i < numWorkers; i++) {
        printf("Enter ratings for worker %d:\n", i + 1);
        for (int j = 0; j < numEvaluations; j++) {
            printf("Evaluation %d: ", j + 1);
            scanf("%d", &*(*(scores + i) + j));
        }
    }
}

void displayRatings(int **scores, int numWorkers, int numEvaluations) {
    for (int i = 0; i < numWorkers; i++) {
        printf("\n\nRatings of worker %d:\n", i + 1);
        for (int j = 0; j < numEvaluations; j++) {
            printf("Evaluation %d: %d\n", j + 1, *(*(scores + i) + j));
        }
    }
}

int findTopWorker(int **scores, int numWorkers, int numEvaluations) {
    int highestAvg = -1, highestIndex;
    for (int i = 0; i < numWorkers; i++) {
        int sum = 0;
        for (int j = 0; j < numEvaluations; j++) {
            sum += *(*(scores + i) + j);
        }
        if (sum / numEvaluations > highestAvg) {
            highestAvg = sum / numEvaluations;
            highestIndex = i;
        }
    }
    return highestIndex;
}

int findBestEvaluationPeriod(int **scores, int numWorkers, int numEvaluations) {
    int highestAvg = -1, bestIndex;
    for (int i = 0; i < numEvaluations; i++) {
        int sum = 0;
        for (int j = 0; j < numWorkers; j++) {
            sum += *(*(scores + j) + i);
        }
        if (sum / numWorkers > highestAvg) {
            highestAvg = sum / numWorkers;
            bestIndex = i;
        }
    }
    return bestIndex;
}

int findLowestWorker(int **scores, int numWorkers, int numEvaluations) {
    int lowestAvg = 9999, lowestIndex;
    for (int i = 0; i < numWorkers; i++) {
        int sum = 0;
        for (int j = 0; j < numEvaluations; j++) {
            sum += *(*(scores + i) + j);
        }
        if (sum / numEvaluations < lowestAvg) {
            lowestAvg = sum / numEvaluations;
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

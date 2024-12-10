#include <stdio.h>
#include <string.h>

struct Player {
    char PlayerName[100];
    int ballScore[12];
    int score;
} player1, player2;

int playGame();
int ValidateScore(int score);
int findWinner(struct Player player1, struct Player player2);
void displayMatchScoreBoard(struct Player player1, struct Player player2);

int main() {
    player1.score = 0;
    player2.score = 0;

    printf("Enter the name of Player 1: ");
    scanf("%s", player1.PlayerName);
    printf("Enter the name of Player 2: ");
    scanf("%s", player2.PlayerName);

    for (int i = 0; i < 12; i++) {
        printf("\nEnter score of %s for ball %d: ", player1.PlayerName, i + 1);
        player1.ballScore[i] = playGame();
        player1.score += player1.ballScore[i];

        printf("Enter score of %s for ball %d: ", player2.PlayerName, i + 1);
        player2.ballScore[i] = playGame();
        player2.score += player2.ballScore[i];
    }

    int result = findWinner(player1, player2);
    if (result == 1)
        printf("\n%s won against %s!\n", player1.PlayerName, player2.PlayerName);
    else if (result == 0)
        printf("\n%s won against %s!\n", player2.PlayerName, player1.PlayerName);
    else
        printf("\nThe match is a draw!\n");

    displayMatchScoreBoard(player1, player2);

    return 0;
}

int playGame() {
    int score;
    scanf("%d", &score);
    if (ValidateScore(score) == 0) {
        printf("Invalid score! Setting score to 0.\n");
        return 0;
    }
    return score;
}

int ValidateScore(int score) {
    return (score >= 0 && score <= 6) ? 1 : 0;
}

int findWinner(struct Player player1, struct Player player2) {
    if (player1.score > player2.score)
        return 1;
    else if (player1.score == player2.score)
        return -1;
    else
        return 0;
}

void displayMatchScoreBoard(struct Player player1, struct Player player2) {
    printf("\n%s's performance in the match:\n", player1.PlayerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d = %d\n", i + 1, player1.ballScore[i]);
    }
    printf("Average score: %.2f\n", (float)player1.score / 12);
    printf("Total score: %d\n", player1.score);
    printf("========================================\n");

    printf("\n%s's performance in the match:\n", player2.PlayerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d = %d\n", i + 1, player2.ballScore[i]);
    }
    printf("Average score: %.2f\n", (float)player2.score / 12);
    printf("Total score: %d\n", player2.score);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_GROUPS 5
#define MAX_DEVICES 3
#define MAX_ITEMS 10

struct Media {
    char name[50];
    float score;
    int duration;
    char format[20];
};

struct User {
    char name[30];
    double *activityScores;
    double **devicePreferences;
};

struct Group {
    struct Media *items[MAX_ITEMS];
};

void initializeUsers(struct User users[], int numUsers);
void setupActivityScores(struct User *user);
void setupDevicePreferences(struct User *user);
void updateActivityScore(struct User *user, int groupIndex, double score);
void displayUserActivity(const struct User *user);
void initializeGroups(struct Group groups[]);
void addItemToGroup(struct Group *group, int itemIndex, const char *name, float score, int duration, const char *format);
void displayGroupItems(const struct Group *group);

int main() {
    struct User users[MAX_USERS];
    struct Group groups[MAX_GROUPS];

    initializeUsers(users, MAX_USERS);
    initializeGroups(groups);

    addItemToGroup(&groups[0], 0, "Action Movie 1", 8.5, 120, "H.264");
    addItemToGroup(&groups[1], 0, "Drama Movie 1", 7.8, 90, "H.265");

    updateActivityScore(&users[0], 0, 5.0);
    updateActivityScore(&users[0], 1, 3.5);

    printf("Activity Scores for %s:\n", users[0].name);
    displayUserActivity(&users[0]);

    printf("\nContents of Action Group:\n");
    displayGroupItems(&groups[0]);

    return 0;
}

void initializeUsers(struct User users[], int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        snprintf(users[i].name, sizeof(users[i].name), "User%d", i + 1);
        users[i].activityScores = (double *)malloc(MAX_GROUPS * sizeof(double));
        memset(users[i].activityScores, 0, MAX_GROUPS * sizeof(double));
        setupDevicePreferences(&users[i]);
    }
}

void setupDevicePreferences(struct User *user) {
    user->devicePreferences = (double **)malloc(MAX_DEVICES * sizeof(double *));
    for (int i = 0; i < MAX_DEVICES; i++) {
        user->devicePreferences[i] = (double *)malloc(3 * sizeof(double));
        memset(user->devicePreferences[i], 0, 3 * sizeof(double));
    }
}

void updateActivityScore(struct User *user, int groupIndex, double score) {
    if (groupIndex >= 0 && groupIndex < MAX_GROUPS) {
        user->activityScores[groupIndex] += score;
    }
}

void displayUserActivity(const struct User *user) {
    for (int i = 0; i < MAX_GROUPS; i++) {
        printf("Group %d Activity Score: %.2f\n", i + 1, user->activityScores[i]);
    }
}

void initializeGroups(struct Group groups[]) {
    for (int i = 0; i < MAX_GROUPS; i++) {
        for (int j = 0; j < MAX_ITEMS; j++) {
            groups[i].items[j] = NULL;
        }
    }
}

void addItemToGroup(struct Group *group, int itemIndex, const char *name, float score, int duration, const char *format) {
    if (itemIndex >= 0 && itemIndex < MAX_ITEMS) {
        group->items[itemIndex] = (struct Media *)malloc(sizeof(struct Media));
        strncpy(group->items[itemIndex]->name, name, sizeof(group->items[itemIndex]->name));
        group->items[itemIndex]->score = score;
        group->items[itemIndex]->duration = duration;
        strncpy(group->items[itemIndex]->format, format, sizeof(group->items[itemIndex]->format));
    }
}

void displayGroupItems(const struct Group *group) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (group->items[i] != NULL) {
            printf("Name: %s \nScore: %.1f \nDuration: %d mins \nFormat: %s\n",
                   group->items[i]->name,
                   group->items[i]->score,
                   group->items[i]->duration,
                   group->items[i]->format);
        }
    }
}

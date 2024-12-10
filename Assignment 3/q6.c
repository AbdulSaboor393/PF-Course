#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct Crop {
    char cropType[20];
    int growthStage;
    float expectedYield;
    Weather *weatherForecast; 
} Crop;

typedef struct Equipment {
    char equipmentType[20];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[50];
} Equipment;

typedef struct Sensor {
    float soilNutrients[5];
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct Field {
    float gpsCoordinates[2];
    float soilHealth[3];
    float moistureLevel;
    Crop *crops; // Pointer to crop array
    Equipment *equipment; // Pointer to equipment array
    Sensor *sensors; // Pointer to sensor array
    int numCrops;
    int numEquipment;
    int numSensors;
} Field;

typedef struct RegionalHub {
    Field *fields; 
    int numFields;
    float aggregateYield;
} RegionalHub;

void initializeField(Field *field, int numCrops, int numEquipment, int numSensors) {
    field->crops = (Crop *)malloc(numCrops * sizeof(Crop));
    field->equipment = (Equipment *)malloc(numEquipment * sizeof(Equipment));
    field->sensors = (Sensor *)malloc(numSensors * sizeof(Sensor));
    field->numCrops = numCrops;
    field->numEquipment = numEquipment;
    field->numSensors = numSensors;

    for (int i = 0; i < numCrops; i++) {
        strcpy(field->crops[i].cropType, "Unknown");
        field->crops[i].growthStage = 0;
        field->crops[i].expectedYield = 0.0;
        field->crops[i].weatherForecast = NULL; // Initialize to NULL
    }

    for (int i = 0; i < numEquipment; i++) {
        strcpy(field->equipment[i].equipmentType, "Unknown");
        field->equipment[i].operationalStatus = 0;
        field->equipment[i].fuelLevel = 0.0;
        strcpy(field->equipment[i].activitySchedule, "Not Scheduled");
    }

    for (int i = 0; i < numSensors; i++) {
        memset(field->sensors[i].soilNutrients, 0, 5 * sizeof(float));
        field->sensors[i].pHLevel = 7.0;
        field->sensors[i].pestActivity = 0; 
    }
}

void freeField(Field *field) {
    for (int i = 0; i < field->numCrops; i++) {
        if (field->crops[i].weatherForecast != NULL) {
            free(field->crops[i].weatherForecast);
        }
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

int main() {
    int numFields = 2;
    Field *fields = (Field *)malloc(numFields * sizeof(Field));
    for (int i = 0; i < numFields; i++) {
        initializeField(&fields[i], 3, 2, 4);
    }

    strcpy(fields[0].crops[0].cropType, "Wheat");
    fields[0].crops[0].expectedYield = 100.5;

    printf("Field 1, Crop 1: %s, Yield: %.2f\n", fields[0].crops[0].cropType, fields[0].crops[0].expectedYield);

    for (int i = 0; i < numFields; i++) {
        freeField(&fields[i]);
    }
    free(fields);

    return 0;
}

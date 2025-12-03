#ifndef HEALTH_H
#define HEALTH_H

// Structure to store user details
typedef struct {
    float weight;       // in kg
    float height;       // in meters
    int age;
    char gender;        // M/F
    int activityLevel;  // 1 - 5
} HealthProfile;

// Function declarations
float calculateBMI(HealthProfile p);
float calculateBMR(HealthProfile p);
float dailyCalories(float bmr, int activityLevel);
float idealWeight(HealthProfile p);
void saveToFile(float bmi, float bmr, float calories, float ideal);

#endif 

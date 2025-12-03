#include <stdio.h>
#include "health.h"

// BMI = weight / (height^2)
float calculateBMI(HealthProfile p) {
    return p.weight / (p.height * p.height);
}

// BMR using Harris-Benedict Formula
float calculateBMR(HealthProfile p) {
    float heightCm = p.height * 100;

    if (p.gender == 'M' || p.gender == 'm')
        return 88.362 + (13.397 * p.weight) + (4.799 * heightCm) - (5.677 * p.age);

    return 447.593 + (9.247 * p.weight) + (3.098 * heightCm) - (4.330 * p.age);
}

// Daily Calorie Requirement
float dailyCalories(float bmr, int activityLevel) {
    float factors[] = {1.2, 1.375, 1.55, 1.725, 1.9};

    if (activityLevel < 1 || activityLevel > 5)
        return bmr * 1.2;

    return bmr * factors[activityLevel - 1];
}

// Ideal weight (Devine Formula)
float idealWeight(HealthProfile p) {
    float heightInch = p.height * 39.37;

    if (heightInch < 60) heightInch = 60;

    if (p.gender == 'M' || p.gender == 'm')
        return 50 + 2.3 * (heightInch - 60);

    return 45.5 + 2.3 * (heightInch - 60);
}

// Save results to file
void saveToFile(float bmi, float bmr, float calories, float ideal) {
    FILE *fp = fopen("health_history.txt", "a");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "BMI: %.2f | BMR: %.2f | Calories: %.2f | Ideal Wt: %.2f\n",
            bmi, bmr, calories, ideal);

    fclose(fp);
}


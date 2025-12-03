#include <stdio.h>
#include "health.h"

int main() {
    HealthProfile user;
    float bmi, bmr, calories, ideal;

    printf("\n===== HEALTH METRIC CALCULATOR =====\n");

    printf("Enter weight (kg): ");
    scanf("%f", &user.weight);

    printf("Enter height (meters): ");
    scanf("%f", &user.height);

    printf("Enter age: ");
    scanf("%d", &user.age);

    printf("Enter gender (M/F): ");
    scanf(" %c", &user.gender);

    printf("\nChoose Activity Level:\n");
    printf("1. Sedentary\n");
    printf("2. Light Exercise\n");
    printf("3. Moderate Exercise\n");
    printf("4. Very Active\n");
    printf("5. Super Active\n");
    printf("Enter choice: ");
    scanf("%d", &user.activityLevel);

    // Calculations
    bmi = calculateBMI(user);
    bmr = calculateBMR(user);
    calories = dailyCalories(bmr, user.activityLevel);
    ideal = idealWeight(user);

    // Output
    printf("\n===== RESULTS =====\n");
    printf("BMI: %.2f\n", bmi);
    printf("BMR: %.2f calories/day\n", bmr);
    printf("Daily Calorie Needs: %.2f calories/day\n", calories);
    printf("Ideal Weight: %.2f kg\n", ideal);

    // Save to file
    saveToFile(bmi, bmr, calories, ideal);

    printf("\nResults saved to 'health_history.txt'\n");

    return 0;
}


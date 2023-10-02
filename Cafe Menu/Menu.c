#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs for Items on the Menu.
struct Beverage {
    char name[50];
    double smallPrice;
    double mediumPrice;
    double largePrice;
};

struct Meal {
    char name[50];
    double price;
};

// Struct to handle the items ordered.
struct OrderItem {
    char name[50];
    double price;
    char size[10];
};


// Print Bill Function
void printBill(struct OrderItem *userSelections, int numBeverageSelections, int numMealSelections) {
    double totalBill = 0.0;                                                                                                                         // Initialize bill total to 0.
    printf("\nYour Bill:\n");

    // Beverage Section in the Bill.
    printf("Beverages:\n");                                                                                                                         
    for (int i = 0; i < numBeverageSelections; i++) {
        printf("%d. %s (%s):\n", i + 1, userSelections[i].name, userSelections[i].size);                                                            
        printf("   Price: $%.2lf\n", userSelections[i].price);

        totalBill += userSelections[i].price;
    }

    // Meal Section in the Bill.
    printf("\nMeals:\n");
    for (int i = 0; i < numMealSelections; i++) {
        printf("%d. %s (%s):\n", i + 1, userSelections[numBeverageSelections + i].name, userSelections[numBeverageSelections + i].size);
        printf("   Price: $%.2lf\n", userSelections[numBeverageSelections + i].price);

        totalBill += userSelections[numBeverageSelections + i].price;
    }

    printf("\nTotal Bill: $%.2lf\n", totalBill);
}



int main() {
    
    // Struct to show to the user the available Beverages.
    struct Beverage beverages[] = {
        {"Coffee", 2.00, 2.50, 3.00},
        {"Tea", 1.50, 2.00, 2.50},
        {"Milkshake", 2.00, 2.50, 3.00}
    };

    // Struct to show to the user the available Meals.
    struct Meal meals[] = {
        {"Sandwich", 5.00 },
        {"Muffin", 2.50 },
        {"Croissant", 3.00},
        {"Bagel", 2.50},
        {"Salad", 6.00},
        {"Burger", 7.00},
        {"Pizza", 8.00},
        {"Pasta", 9.00},
    };

    int beverageCount = sizeof(beverages) / sizeof(beverages[0]);               // Keep track of number of ordered beverages as will be needed to loop through for when bill to be printed.
    int mealCount = sizeof(meals) / sizeof(meals[0]);                           // Same as above but for meals.

    printf("Welcome to the Cafe Menu!\n");
    printf("------------------------------\n");

    int numBeverageSelections = 0;
    int numMealSelections = 0;
    int maxSelections = beverageCount + mealCount;
    struct OrderItem *userSelections = (struct OrderItem *)malloc(sizeof(struct OrderItem) * maxSelections);            // Dynamically allocate memory with pointer pointing to the memory.
                                                                                                                        // This stores the users selections in the heap.

    printf("Beverages:\n");
    for (int i = 0; i < beverageCount; i++) {
        printf("B%d. %s:\n", i + 1, beverages[i].name);
        printf("   Small: $%.2lf\n", beverages[i].smallPrice);
        printf("   Medium: $%.2lf\n", beverages[i].mediumPrice);
        printf("   Large: $%.2lf\n", beverages[i].largePrice);
    }

    printf("\nMeals + Snacks\t    Price\n\n");
    for (int i = 0; i < mealCount; i++) {
        printf("M%d. %s\t", i + 1, meals[i].name);
        printf("    $%.2lf\n", meals[i].price);
    }

    printf("Enter 0 to Quit");


    // User Selection Handling
    while (1) {
        char selection[4];
        printf("\nEnter your selection:");
        scanf("%s", selection);

        if (strcmp(selection, "0") == 0) {
            break;
        } else if (strncmp(selection, "B", 1) == 0) {
            int beverageNumber = atoi(selection + 1);
            if (beverageNumber >= 1 && beverageNumber <= beverageCount) {
                if (numBeverageSelections < maxSelections) {
                    char sizeSelection;
                    printf("Select size for %s (S for Small, M for Medium, L for Large): ", beverages[beverageNumber - 1].name);
                    scanf(" %c", &sizeSelection);

                    switch (sizeSelection) {
                        case 'S':
                        case 's':
                            strcpy(userSelections[numBeverageSelections].name, beverages[beverageNumber - 1].name);
                            strcpy(userSelections[numBeverageSelections].size, "Small");
                            userSelections[numBeverageSelections].price = beverages[beverageNumber - 1].smallPrice;
                            numBeverageSelections++;
                            break;
                        case 'M':
                        case 'm':
                            strcpy(userSelections[numBeverageSelections].name, beverages[beverageNumber - 1].name);
                            strcpy(userSelections[numBeverageSelections].size, "Medium");
                            userSelections[numBeverageSelections].price = beverages[beverageNumber - 1].mediumPrice;
                            numBeverageSelections++;
                            break;
                        case 'L':
                        case 'l':
                            strcpy(userSelections[numBeverageSelections].name, beverages[beverageNumber - 1].name);
                            strcpy(userSelections[numBeverageSelections].size, "Large");
                            userSelections[numBeverageSelections].price = beverages[beverageNumber - 1].largePrice;
                            numBeverageSelections++;
                            break;
                        default:
                            printf("Invalid size selection. Please select a valid size (S, M, L).\n");
                            continue; // Continue the loop
                    }
                } else {
                    printf("Maximum selections reached.\n");
                    break;
                }
            } else {
                printf("Invalid selection. Please enter a valid item number or 0 to finish.\n");
                continue; // Continue the loop
            }
        } else if (strncmp(selection, "M", 1) == 0) {
            int mealNumber = atoi(selection + 1);
            if (mealNumber >= 1 && mealNumber <= mealCount) {
                if (numMealSelections < maxSelections) {
                    struct Meal selectedMeal = meals[mealNumber - 1];
                    strcpy(userSelections[numMealSelections + numBeverageSelections].name, selectedMeal.name);
                    strcpy(userSelections[numMealSelections + numBeverageSelections].size, "N/A"); // No size for meals
                    userSelections[numMealSelections + numBeverageSelections].price = selectedMeal.price;
                    numMealSelections++;
                } else {
                    printf("Maximum selections reached.\n");
                    break;
                }
            } else {
                printf("Invalid selection. Please enter a valid item number or 0 to finish.\n");
                continue; // Continue the loop
            }
        } else {
            printf("Invalid selection format. Please enter a valid item number or 0 to finish.\n");
        }
    }

    // Print the bill using the printBill function
    printBill(userSelections, numBeverageSelections, numMealSelections);

    // Clean up allocated memory
    free(userSelections);

    return 0;
}

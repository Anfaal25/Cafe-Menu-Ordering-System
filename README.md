# Cafe Menu Ordering System

## Introduction
Welcome to the Cafe Menu Ordering System! This C program allows customers to place orders from a menu consisting of beverages and meals. Customers can select from a variety of beverages like coffee, tea, and milkshakes, as well as meals such as sandwiches, muffins, burgers, and more. The program calculates the total bill based on the customer's selections and provides a detailed bill summary.

## Features
- Displays a list of available beverages and meals with prices and sizes.
- Supports ordering multiple beverages and meals.
- Allows customers to choose the size for beverages (Small, Medium, Large).
- Dynamically allocates memory for storing user selections.
- Provides a detailed bill including item names, sizes, and total price.

## How to Use
1. Clone the repository to your local machine using the following command:
   ```sh
   git clone [https://github.com/Anfaal25/Cafe-Menu-Ordering-System.git]
   ```
2. Navigate to the project directory:
   ```sh
   cd Cafe-Menu-Ordering-System
   ```
3. Compile the program using a C compiler (e.g., GCC):
   ```sh
   gcc main.c -o cafe_menu
   ```
4. Run the compiled program:
   ```sh
   ./cafe_menu
   ```
5. Follow the on-screen instructions to place your order.
   - Enter `B[number]` to select a beverage (e.g., B1 for Coffee).
   - Enter `M[number]` to select a meal (e.g., M1 for Sandwich).
   - Enter `S`, `M`, or `L` to choose the size for beverages.
   - Enter `0` to finish your order and generate the bill.

## Example
```
Welcome to the Cafe Menu!
------------------------------
Beverages:
B1. Coffee:
   Small: $2.00
   Medium: $2.50
   Large: $3.00
B2. Tea:
   Small: $1.50
   Medium: $2.00
   Large: $2.50
B3. Milkshake:
   Small: $2.00
   Medium: $2.50
   Large: $3.00

Meals + Snacks	    Price

M1. Sandwich	    $5.00
M2. Muffin	    $2.50
M3. Croissant	$3.00
M4. Bagel	    $2.50
M5. Salad	    $6.00
M6. Burger	    $7.00
M7. Pizza	    $8.00
M8. Pasta	    $9.00

Enter 0 to Quit
Enter your selection: B1
Select size for Coffee (S for Small, M for Medium, L for Large): M
Enter your selection: M3
Enter your selection: B2
Select size for Tea (S for Small, M for Medium, L for Large): L
Enter your selection: 0

Your Bill:
Beverages:
1. Coffee (Medium):
   Price: $2.50
2. Tea (Large):
   Price: $2.50

Meals:
1. Croissant (N/A):
   Price: $3.00

Total Bill: $8.00
```

## Conclusion
This Cafe Menu Ordering System demonstrates the functionality of dynamic memory allocation, user input handling, and struct usage in C programming. Feel free to explore the code, modify it, and use it as a reference for your own projects.

For any questions or feedback, please feel free to contact me at [anfaalmahbub25@gmail.com](mailto:anfaalmahbub25@gmail.com).

Thank you for using the Cafe Menu Ordering System! Enjoy your meal!

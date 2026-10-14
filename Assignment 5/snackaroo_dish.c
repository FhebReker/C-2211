#include "snackaroo_dish.h"

Dish *insert_dish(Dish *root, int new_code, char *new_name, char *new_restaurant, float new_rating, float new_price){
    // Allocate memory for new dish and check if memory is valid for storage
    Dish *new_dish = malloc(sizeof(Dish));
    if (!new_dish) {
        printf("Error: malloc failed in insert_dish\n");
        return root;
    }
    
    // Initialize new dish with arguments
    new_dish->dish_code = new_code;
    strncpy(new_dish->dish_name, new_name, 99); new_dish->dish_name[99] = '\0';
    strncpy(new_dish->resteraunt_name, new_restaurant, 99); new_dish->resteraunt_name[99] = '\0';
    new_dish->average_customer_rating = new_rating;
    new_dish->price = new_price;
    new_dish->next_dish = NULL;
    

    //  No dishes were added yet, return the new dish to be the next root
    if (!root) {return new_dish;}

    // Find next open spot in linked list and add there
    Dish *current = root;
    while (current->next_dish) {current = current->next_dish;}
    current->next_dish = new_dish;
    return root;
} /*Asks for unique code, name, resteraunt, dish rating and dish price*/

Dish *search_dish (Dish *root, int dish_code){
    // Go down the list to find a dish with the specified code
    Dish* current = root;
    while (current) {
        if (current->dish_code == dish_code) {return current;} // print out dish
        current = current->next_dish;
    }

    return NULL;// Dish code isn't in database
} /*Search based on dish code, then print out all values*/

void update_dish(Dish *root, int dish_code, char *new_name, char *new_restaurant, float new_rating, float new_price) {
    Dish *dish_to_update = search_dish(root, dish_code);
    if (!dish_to_update) {return;} // return if not in database

    // Update dish with provided values
    strncpy(dish_to_update->dish_name, new_name, 99); dish_to_update->dish_name[99] = '\0';
    strncpy(dish_to_update->resteraunt_name, new_restaurant, 99); dish_to_update->resteraunt_name[99] = '\0';
    dish_to_update->average_customer_rating = new_rating;
    dish_to_update->price = new_price;
    return;
} /*Find via dish code, then update values for the dish*/

void print_dish(Dish *dish) {
    printf("Dish Code\t");
    printf("Dish Name\t\t");
    printf("Resteraunt Name\t\t");
    printf("Dish Rating\t\t");
    printf("Dish Price\n");

    printf("%-9d\t", dish->dish_code);
    printf("%-20s\t", dish->dish_name);
    printf("%-20s\t", dish->resteraunt_name);
    printf("%-20.1f\t", dish->average_customer_rating);
    printf("$%-0.2f\n", dish->price);
} /*Print out a single dish with code, name, resteraunt, rating and price*/

void print_dishes(Dish *root) {
    // Check if there are any dishes in the database
    if (!root) {
        printf("No dishes currently in database!\n");
        return;
    }

    // Print header
    printf("Dish Code\t");
    printf("Dish Name\t\t");
    printf("Resteraunt Name\t\t");
    printf("Dish Rating\t");
    printf("Dish Price\n");

    // Print out all dishes in database
    Dish *current = root;
    while (current) {
        // Print dish row
        printf("%-9d\t", current->dish_code);
        printf("%-20s\t", current->dish_name);
        printf("%-20s\t", current->resteraunt_name);
        printf("%-10.1f\t", current->average_customer_rating);
        printf("$%-.2f\n", current->price);

        current = current->next_dish;
    }
} /*Print out all dishes with code, name, resteraunt, rating and price*/

Dish *erase_dish(Dish *root, int dish_code) {
    // Initialize variables
    Dish *previous_dish = NULL, *dish_to_erase = root;
    
    // Loop until reached position
    while (dish_to_erase && dish_to_erase->dish_code != dish_code) {
        previous_dish = dish_to_erase;
        dish_to_erase = dish_to_erase->next_dish;
    }

    // Return if not in the database
    if (!dish_to_erase) {return NULL;}

    // Otherwise overwrite pointer to position based on if in first position or later position
    else if (!previous_dish) {root = root->next_dish;}
    else{ previous_dish->next_dish = dish_to_erase->next_dish;} 
    free(dish_to_erase);
    return root;
} /*Find dish, then remove from linked list if found*/
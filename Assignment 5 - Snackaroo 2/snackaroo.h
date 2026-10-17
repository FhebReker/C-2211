#ifndef SNACKAROO_H_
#define SNACKAROO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dish Struct
typedef struct Dish{
    int dish_code; // Assumed x >= 0
    char dish_name[100]; // extra characters are trimmed off
    char resteraunt_name[100]; // extra characters are trimmed off
    float average_customer_rating; // Assumed 0.0 <= x <= 10.0
    float price; // Assumed x > 0
    struct Dish *next_dish; // For linked list
} Dish;

// Driver Struct
typedef struct Driver{
    int driver_code; // Assumed x >= 0
    char driver_name[50]; // extra characters are trimmed off
    int vehicle_colour; // 0 = red, 1 = green, 2 = blue, 3 = grey, 4 = white, 5 = black, 6 = other; 0 <= x <= 6
    char licence_plate[9]; // Alphanumeric characters + space, 2 <= len(licence_plate), extra characters are trimmed off so len(licence_plate) <= 8 always
    struct Driver *next_driver; // For linked list
} Driver;

void print_help(); // press h to ask for all commands
int control_dishes(Dish **root, char choice); // press m to switch to dish menu
int control_drivers(Driver **root, char choice); // press a to switch to driver menu

#endif
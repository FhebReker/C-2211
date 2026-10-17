#ifndef SNACKAROO_DISH_H_
#define SNACKAROO_DISH_H_

#include "snackaroo.h"

// Class prototypes
Dish *insert_dish(Dish *root, int new_code, char *new_name, char *new_restaurant, float new_rating, float new_price); /*Asks for unique code, name, resteraunt, dish rating and dish price*/
Dish *search_dish (Dish *root, int dish_code); /*Search based on dish code, then print out all values*/
void update_dish(Dish *root, int dish_code, char *new_name, char *new_restaurant, float new_rating, float new_price); /*Find via dish code, then update values for the dish*/
void print_dish(Dish *dish); /*Print single instance of a dish*/
void print_dishes(Dish *root); /*Print out all dishes with code, name, resteraunt, rating and price*/
Dish *erase_dish(Dish *root, int dish_code); /*Find dish, then remove from linked list if found*/

#endif
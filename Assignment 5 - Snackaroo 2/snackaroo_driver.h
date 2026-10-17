#ifndef SNACKAROO_DRIVER_H_
#define SNACKAROO_DRIVER_H_

#include "snackaroo.h"

// Class prototypes
Driver *insert_driver(Driver *root, int new_code, char *new_name, int new_colour, char *new_licence_plate); /*Asks for unique code, name, colour, and licence plate*/
Driver *search_driver(Driver *root, int driver_code); // Find driver code, then print driver information
void update_driver(Driver *root, int driver_code, char *new_name, int new_colour, char *new_licence_plate); // Find driver code, then ask for info again
void print_driver(Driver *driver); // Print single instance of a driver
void print_drivers(Driver *root); // Print all drivers with their infos
Driver *erase_driver(Driver *root, int driver_code); // Find driver code, then remove from linked list

#endif
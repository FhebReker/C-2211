#include "snackaroo_driver.h"

const char* colours[7] = {"Red", "Green", "Blue", "Grey", "White", "Black", "Other"};

Driver *insert_driver(Driver *root, int new_code, char *new_name, int new_colour, char *new_licence_plate) {
    // Allocate memory for new driver and check if memory is valid for storage
    Driver *new_driver = malloc(sizeof(Driver));
    if (!new_driver) {
        printf("Error: malloc failed in insert_driver\n");
        return root;
    }
    
    // Initialize new driver with arguments
    new_driver->driver_code = new_code;
    strncpy(new_driver->driver_name, new_name, 49); new_driver->driver_name[49] = '\0';
    new_driver->vehicle_colour = new_colour;
    strncpy(new_driver->licence_plate, new_licence_plate, 9); new_driver->licence_plate[9] = '\0';
    new_driver->next_driver = NULL;
    

    //  No drivers were added yet, return the new driver to be the next root
    if (!root) {return new_driver;}

    // Find next open spot in linked list
    Driver *current = root;
    while (current->next_driver) {current = current->next_driver;}
    current->next_driver = new_driver;
    return root;
} /*Asks for unique code, name, colour, and licence plate*/

Driver *search_driver(Driver *root, int driver_code) {
    // Go down the list to find a driver with the specified code
    Driver* current = root;
    while (current) {
        if (current->driver_code == driver_code) {return current;} // print out driver?
        current = current->next_driver;
    }

    return NULL;// Driver code isn't in database
} // Find driver code, then print driver information

void update_driver(Driver *root, int driver_code, char *new_name, int new_colour, char *new_licence_plate) {
    Driver *driver_to_update = search_driver(root, driver_code);
    if (!driver_to_update) {return;} // return if not in database

    // Update driver with provided values
    strncpy(driver_to_update->driver_name, new_name, 50); driver_to_update->driver_name[50] = '\0';
    driver_to_update->vehicle_colour = new_colour;
    strncpy(driver_to_update->licence_plate, new_licence_plate, 9); driver_to_update->licence_plate[9] = '\0';
    return;
} // Find driver code, then ask for info again

void print_driver(Driver *driver) {
    printf("Driver Code\t");
    printf("Driver Name\t\t");
    printf("Vehicle Colour\t");
    printf("Licence Plate\n");

    printf("%-9d\t", driver->driver_code);
    printf("%-20s\t", driver->driver_name);
    printf("%-10s\t\t", colours[driver->vehicle_colour]);
    printf("%-20s\n", driver->licence_plate);
} // Print a single driver with their info

void print_drivers(Driver *root) {
    // Check if there are any dishes in the database
    if (!root) {
        printf("No drivers currently in database!\n");
        return;
    }

    // Print header
    printf("Driver Code\t");
    printf("Driver Name\t\t");
    printf("Vehicle Colour\t");
    printf("Licence Plate\n");

    // Print out all drivers in database
    Driver *current = root;
    while (current) {
        // Print driver row
        printf("%-9d\t", current->driver_code);
        printf("%-20s\t", current->driver_name);
        printf("%-10s\t", colours[current->vehicle_colour]);
        printf("%-20s\n", current->licence_plate);

        current = current->next_driver;
    }
} // Print all drivers with their infos

Driver *erase_driver(Driver *root, int driver_code) {
    // Initialize variables
    Driver *previous_driver = NULL, *driver_to_erase = root;
    
    // Loop until reached position
    while (driver_to_erase && driver_to_erase->driver_code != driver_code) {
        previous_driver = driver_to_erase;
        driver_to_erase = driver_to_erase->next_driver;
    }

    // Return if not in the database 
    if (!driver_to_erase) {return NULL;}

    // Otherwise overwrite pointer to position based on if in first position or later position
    else if (!previous_driver) {root = root->next_driver;}
    else{ previous_driver->next_driver = driver_to_erase->next_driver;}    
    free(driver_to_erase);
    return root;
} // Find driver code, then remove from linked list
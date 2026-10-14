#include "snackaroo.h"
#include "snackaroo_dish.h"
#include "snackaroo_driver.h"
#include <ctype.h>


void print_help() {
    printf("Available commands to perform:\n");
    printf("Ask for help in using the program (h)\n");
    printf("Move to Dish Control (m)\n");
    printf("Move to Driver Control (a)\n");
    printf("Quit the program (q)\n\n");

    printf("Available commands in the Dish or Driver sub-menus:\n");
    printf("Insert a new dish/driver into the database (i)\n");
    printf("Search for a dish/driver by code (s)\n");
    printf("Update a dish/driver by code (u)\n");
    printf("Print out every dish/driver currently in the database (p)\n");
    printf("Erase a dish/driver from the database by code (e)\n\n");

    printf("In any case where there is an invalid input, you will be returned to the main menu and reprompted\n");
} // press h to ask for all commands

int control_dishes(Dish **root, char choice) {
    printf("Enter a command in the Dishes sub-menu to perform: ");
    scanf(" %c", &choice);

    // Initialize variables
    int new_dish_code;
    char new_dish_name[100];
    char new_resteraunt_name[100];
    float new_average_customer_rating; 
    float new_price;
    
    switch (choice){
        case 'i': // Insert dish
            printf("Inserting a new dish:\n");

            // Dish Code Input
            printf("Enter your dish's code (greater or equal to 0 and not already taken): ");
            // Scan (clear buffer if needed)
            if (scanf("%d", &new_dish_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish code must be an integer greater or equal to 0.\n");
                return -1; // Return without adding dish at dish code input stage
            }
            getchar();
            // Check if invalid code or taken
            if (new_dish_code < 0) {
                printf("\tYour dish code must be equal or greater than 0.\n");    
                return -1; // Return without adding dish at dish code input stage
            }
            else if (search_dish(*root, new_dish_code)) {
                printf("\tThis dish code is already taken.\n");
                return -1; // Return without adding dish at dish code input stage
            }


            // Dish Name Input
            printf("Enter your dish's name (maximum 99 characters): "); 
            fgets(new_dish_name, sizeof(new_dish_name), stdin);
            if (new_dish_name[strlen(new_dish_name) - 1] == '\n') new_dish_name[strlen(new_dish_name) - 1] = '\0';


            // Resteraunt Name Input
            printf("Enter where your dish is sold (maximum 99 characters): ");
            fgets(new_resteraunt_name, sizeof(new_resteraunt_name), stdin);
            if (new_resteraunt_name[strlen(new_resteraunt_name) - 1] == '\n') new_resteraunt_name[strlen(new_resteraunt_name) - 1] = '\0';


            // Average Rating Input
            printf("Enter the average rating your dish has (from 0.0 to 10.0, inclusive): ");
            // Scan (clear buffer if needed)
            if (scanf("%f", &new_average_customer_rating) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish rating must be an integer between 0.0 to 10.0.\n");
                return -2; // Return without adding dish at rating input stage
            }
            // Check if rating is in range
            if (new_average_customer_rating < 0.0 || new_average_customer_rating > 10.0) {
                printf("\tYour dish's rating must be between 0.0 and 10.0.\n");
                return -2; // Return without adding dish at rating input stage
            }
            

            // Price Input
            printf("Enter your dish's price (greater than 0): ");
            // Scan (clear buffer if needed)
            if (scanf("%f", &new_price) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish price must be an integer greater than 0.\n");
                return -3; // Return without adding dish at price input stage
            }
            // Check if price is valid
            if (new_price <= 0.0) {
                printf("\tYour dish's price must be greater than 0.\n");
                return -3; // Return without adding dish at price input stage
            }


            // Add dish to database and return success
            *root = insert_dish(*root, new_dish_code, new_dish_name, new_resteraunt_name, new_average_customer_rating, new_price);
            return 1;

        case 's': // Search dish
            int search_code;
            printf("Enter dish code: ");
            
            // Scan (clear buffer if needed)
            if (scanf("%d", &search_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish code must be an integer greater or equal to 0.\n");
                return -1; // Return without finding dish at code input stage
            }
            if (search_code < 0) {
                printf("\tYour dish code must be greater or equal to 0.\n");
                return -1; // Return without finding dish at code input stage
            }
            getchar();
            printf("Searching for specified dish:\n");

            // Search for dish and print if found, returning either success or failure
            Dish *target_dish = search_dish(*root, search_code);
            if (search_code < 0 || !target_dish) {
                printf("\tDish code not found in Snackaroo's database.\n");
                return -2; // Return without finding dish at dish retrieval stage
            }
            print_dish(target_dish);
            return 1;

        case 'u': // Update dish
            int code_of_update;
            printf("Enter dish code: ");

            // Scan (clear buffer and return if needed)
            if (scanf("%d", &code_of_update) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish code must be an integer greater or equal to 0.\n");
                return -1; // Return without updating dish at code input stage
            }
            // Check if code is valid or not in database
            if (code_of_update < 0) {
                printf("\tYour dish code must be greater or equal to 0.\n");
                return -1; // Return without updating dish at code input stage
            }
            if (!search_dish(*root, code_of_update)) {
                printf("\tYour dish code must already be in the database.\n");
                return -1; // Return without updating dish at code input stage
            }
            getchar();


            // Dish Name Input
            printf("Enter your dish's name (maximum 99 characters): "); 
            fgets(new_dish_name, sizeof(new_dish_name), stdin);
            if (new_dish_name[strlen(new_dish_name) - 1] == '\n') new_dish_name[strlen(new_dish_name) - 1] = '\0';


            // Resteraunt Name Input
            printf("Enter where your dish is sold (maximum 99 characters): ");
            fgets(new_resteraunt_name, sizeof(new_resteraunt_name), stdin);
            if (new_resteraunt_name[strlen(new_resteraunt_name) - 1] == '\n') new_resteraunt_name[strlen(new_resteraunt_name) - 1] = '\0';
            

            // Average Rating Input
            printf("Enter the average rating your dish has (from 0.0 to 10.0, inclusive): ");
            // Scan (clear buffer if needed)
            if (scanf("%f", &new_average_customer_rating) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish rating must be an integer between 0.0 to 10.0.\n");
                return -2; // Return without updating dish at dish rating input stage
            }
            // Check if rating is in range
            if (new_average_customer_rating < 0.0 || new_average_customer_rating > 10.0) {
                printf("\tYour dish's rating must be between 0.0 and 10.0.\n");
                return -2; // Return without updating dish at rating input stage
            }

            
            // Price Input
            printf("Enter your dish's price (greater than 0): ");
            // Scan (clear buffer if needed)
            if (scanf("%f", &new_price) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish price must be an integer greater than 0.\n");
                return -3; // Return without updating dish at dish price input stage
            }
            // Check if price is valid
            if (new_price <= 0.0) {
                printf("\tYour dish's price must be greater than 0.\n");
                return -3; // Return without updating dish at price input stage
            }


            // Update dish and return
            update_dish(*root, code_of_update, new_dish_name, new_resteraunt_name, new_average_customer_rating, new_price);
            return 1;
        
        case 'p': // Print dishes
            print_dishes(*root);
            return 1;

        case 'e':
            int erasure_code;
            printf("Enter dish code: ");

            // Scan (clear buffer if needed)
            if (scanf("%d", &erasure_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour dish code must be an integer greater or equal to 0.\n");
                return -1; // Return without erasing dish at invalid code stage
            }
            // Check if invalid code or not in database
            if (erasure_code < 0) { 
                printf("\tYour dish code must be greater or equal to 0.\n");
                return -1; // Return without erasing dish at invalid code stage
            }
            if (!search_dish(*root, erasure_code)) {
                printf("\tYour dish code is not in the database.\n");
                return -1; // Return without erasing dish at invalid code stage
            }

            // Erase dish and return
            *root = erase_dish(*root, erasure_code);
            return 1;

        default:
            while (getchar() != '\n');  // handle multiple character input
            printf("Please enter a valid command! (i: insert a dish, s: search for a dish, u: update a dish, p: print out all dishes, e: erase dish)\n");
            return 1;
    }
} // press m to switch to dish menu

int control_drivers(Driver **root, char choice) {
    printf("Enter a command in the Driver sub-menu to perform: ");
    scanf(" %c", &choice);

    // Initialize variables
    int new_driver_code;
    char new_driver_name[50];
    int new_vehicle_colour;
    char new_licence_plate[9];
    const char* colours[7] = {"Red", "Green", "Blue", "Grey", "White", "Black", "Other"};

    
    switch (choice) {
        case 'i': // Insert a driver 
            printf("Inserting a new driver:\n");

            // Driver Code Input
            printf("Enter your driver's code (greater or equal to 0 and not already taken): ");
            // Scan (clear buffer if needed)
            if (scanf("%d", &new_driver_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour driver code must be an integer greater or equal to 0.\n");
                return -1; // Return without adding driver at driver code input stage
            }
            getchar();
            // Check if invalid code or taken
            if (new_driver_code < 0) {
                printf("\tYour driver code must be equal or greater than 0.\n");    
                return -1; // Return without adding driver at driver code input stage
            }
            else if (search_driver(*root, new_driver_code)) {
                printf("\tThis driver code is already taken.\n");
                return -1; // Return without adding driver at driver code input stage
            }


            // Driver Name Input
            printf("Enter your driver's name (maximum 50 characters): "); 
            fgets(new_driver_name, sizeof(new_driver_name), stdin);
            if (new_driver_name[strlen(new_driver_name) - 1] == '\n') new_driver_name[strlen(new_driver_name) - 1] = '\0';


            // Vehicle Colour Input
            printf("Enter your vehicle's colour (");
            for (int i = 0; i < 7; i++) {
                printf("%d = %s", i, colours[i]);
                if (i != 6) printf(", ");
                else printf("): ");
            }
            // Scan (clear buffer if needed)
            if (scanf("%d", &new_vehicle_colour) != 1) {
                while (getchar() != '\n');
                printf("\tYour vehicle's colour must be an integer within the range of 0-6.\n");
                return -3; // Return without adding driver at vehicle colour stage
            }
            getchar();
            // Check if colour is valid
            if (new_vehicle_colour < 0 || new_vehicle_colour > 6) {
                printf("\tYour vehicle's colour must be within the range of 0-6.\n");
                return -3; // Return without adding driver at vehicle colour stage
            }


            // Licence Plate Input
            printf("Enter your driver's licence plate: ");
            fgets(new_licence_plate, sizeof(new_licence_plate), stdin);
            if (new_licence_plate[strlen(new_licence_plate) - 1] == '\n') new_licence_plate[strlen(new_licence_plate) - 1] = '\0';
            if (strlen(new_licence_plate) >= 8) while (getchar() != '\n');
            // Check if licence plate is valid or less than 2 characters in length
            if (strlen(new_licence_plate) < 1) {
                printf("\tYour vehicle's licence plate must be between 2-8 characters long.\n");
                return -4;
            }
            for (int i = 0; i < (int) strlen(new_licence_plate) && (new_licence_plate[i] != '\0' || new_licence_plate[i] != '\n'); i++) {
                if (!isalnum(new_licence_plate[i]) && (new_licence_plate[i] != '\0' && new_licence_plate[i] != '\n' && new_licence_plate[i] != ' ')) {
                    printf("<%c>\n", new_licence_plate[i]);
                    printf("\tYour vehicle's licence plate must consist of alphanumeric characters or spaces.\n");
                    return -4;
                }
            }

            
            // Add driver to database and return success
            *root = insert_driver(*root, new_driver_code, new_driver_name, new_vehicle_colour, new_licence_plate);
            return 1;

        case 's': // Search driver
            int search_code;
            printf("Enter driver code: ");
            
            // Scan (clear buffer if needed)
            if (scanf("%d", &search_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour driver's code must be an integer greater or equal to 0.\n");
                return -1; // Return without finding driver at code input stage
            }
            if (search_code < 0) {
                printf("\tYour driver code must be greater or equal to 0.\n");
                return -1; // Return without finding driver at code input stage
            }
            getchar();
            printf("Searching for specified driver:\n");

            // Search for driver and print+return if found
            Driver *target_driver = search_driver(*root, search_code);
            if (!target_driver) {
                printf("\tDriver code not found in Snackaroo's database.\n");
                return -2; // Return without finding driver at driver retrieval stage
            }
            print_driver(target_driver);
            return 1;

        case 'u': // Update driver
            int code_of_update;
            printf("Enter driver code: ");

            // Scan (clear buffer if needed)
            if (scanf("%d", &code_of_update) != 1) {
                while (getchar() != '\n');
                printf("\tYour driver code must be an integer greater or equal to 0.\n");
                return -1; // Return without updating driver at driver code input stage
            }
            // Check if invalid code
            if (code_of_update < 0) {
                printf("\tYour driver code must be greater or equal to 0.\n");
                return -1; // Return without updating driver at driver code input stage
            }
            // Check if code is taken
            else if (!search_driver(*root, code_of_update)) {
                printf("\tYour driver code must already be in the database.\n");
                return -1; // Return without updating driver at driver code input stage
            }
            getchar();


            // Driver Name Input
            printf("Enter your driver's name (maximum 99 characters): "); 
            fgets(new_driver_name, sizeof(new_driver_name), stdin);
            if (new_driver_name[strlen(new_driver_name) - 1] == '\n') new_driver_name[strlen(new_driver_name) - 1] = '\0';


            // Vehicle Colour Input
            printf("Enter your vehicle's colour (");
            for (int i = 0; i < 7; i++) {
                printf("%d = %s", i, colours[i]);
                if (i != 6) printf(", ");
                else printf("): ");
            }
            // Scan (clear buffer if needed)
            if (scanf("%d", &new_vehicle_colour) != 1) {
                while (getchar() != '\n');
                printf("\tYour vehicle price must be an integer greater than 0.\n");
                return -3; // Return without updating driver at vehicle colour stage
            }
            getchar();
            // Check if price is valid
            if (new_vehicle_colour < 0 || new_vehicle_colour > 6) {
                printf("\tYour vehicle's colour must be within the range of 0-6.\n");
                return -3; // Return without updating driver at vehicle colour stage
            }


            // Licence Plate Input
            printf("Enter your driver's licence plate: ");
            fgets(new_licence_plate, sizeof(new_licence_plate), stdin);
            if (new_licence_plate[strlen(new_licence_plate) - 1] == '\n') new_licence_plate[strlen(new_licence_plate) - 1] = '\0';
            if (strlen(new_licence_plate) >= 8) while (getchar() != '\n');
            // Check if licence plate is valid or less than 2 characters in length 
            if (strlen(new_licence_plate) < 1) {
                printf("\tYour vehicle's licence plate must be between 2-8 characters long.\n");
                return -4; // Return without updating driver at vehicle colour stage
            }
            for (int i = 0; i < (int) strlen(new_licence_plate) && (new_licence_plate[i] != '\0' || new_licence_plate[i] != '\n'); i++) {
                if (!isalnum(new_licence_plate[i]) && (new_licence_plate[i] != '\0' && new_licence_plate[i] != '\n')) {
                    printf("\tYour vehicle's licence plate must consist of alphanumeric characters or spaces.\n");
                    return -4; // Return without updating driver at vehicle colour stage
                }
            }

            
            // Update driver and return
            update_driver(*root, code_of_update, new_driver_name, new_vehicle_colour, new_licence_plate);
            return 1;
        
        case 'p': // Print drivers
            print_drivers(*root);
            return 1;

        case 'e':
            int erasure_code;
            printf("Enter driver code: ");

            // Scan (clear buffer if needed)
            if (scanf("%d", &erasure_code) != 1) {
                while (getchar() != '\n');
                printf("\tYour driver code must be an integer greater or equal to 0.\n");
                return -1; // Return at erasure code input stage
            }
            // Check if invalid code or not in database
            if (erasure_code < 0) { 
                printf("\tYour driver code must be greater or equal to 0.\n");
                return -1; // Return at erasure code input stage
            }
            if (!search_driver(*root, erasure_code)) {
                printf("\tYour driver code is not in the database.\n");
                return -1; // Return at erasure code input stage
            }

            // Erase driver and return
            *root = erase_driver(*root, erasure_code);
            return 1;

        default:
            while (getchar() != '\n'); // handle multiple character input
            printf("Please enter a valid command! (i: insert a driver, s: search for a driver, u: update a driver, p: print out all drivers, e: erase driver)\n");
            return 1;
    }
    printf("\n");
} // press a to switch to driver menu



int main(){
    Dish *dish_root = NULL;
    Driver *driver_root = NULL;
    char choice;

    
    printf("**********************************\n");
    printf("*    Welcome to The Snackaroo!   *\n");
    printf("**********************************\n\n");

    printf("Available commands to perform:\n");
    printf("Ask for help in using the program (h)\n");
    printf("Move to Dish Control (m)\n");
    printf("Move to Driver Control (a)\n");
    printf("Quit the program (q)\n\n");

    while (1) {
        printf("****************************************************************************************************\n");
        printf("Enter a command in the main menu to perform: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'h':
                print_help();
                break;

            case 'm':
                control_dishes(&dish_root, choice);
                break;

            case 'a':
                control_drivers(&driver_root, choice);
                break;

            case 'q':
                printf("****************************************************************************************************\n");
                return 0; // press q to leave

            default:
                while (getchar() != '\n');  // handle multiple character input
                printf("Please enter a valid command! (h: ask for help, m: control dishes, a: control drivers, q: quit program)\n");
                break;
        }
        printf("****************************************************************************************************\n\n\n");
    }
}
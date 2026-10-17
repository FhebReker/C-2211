#include <stdio.h>
#include <string.h>

// Define Dish structure
typedef struct
{
    int dish_code; // Assumed x >= 0
    char dish_name[100];
    char resteraunt_name[100];
    float average_customer_rating; // Assumed 0.0 <= x <= 10.0
    float price; // Assumed x > 0
} Dish; // does placement of Dish matter? 

// Macro for maximum dishes
#define MAX_DISHES 100

// Function prototypes
int insert_dish(Dish database[], int total_dishes);
int search_dish (Dish database[], int total_dishes, int dish_code, _Bool to_print_dish);
int update_dish(Dish database[], int total_dishes, int dish_code);
void print_dish(Dish dish, _Bool first_to_print);
void print_dishes(Dish database[], int total_dishes);

// Main
int main() {
    // Initialize variables
    char choice;
    Dish snackaroo_database[MAX_DISHES];
    int dish_count = 0;


    printf("**********************************\n");
    printf("*    Welcome to The Snackaroo!       *\n");
    printf("**********************************\n\n");

    printf("Available commands to perform:\n");
    printf("Insert a new dish into the Snackaroo database (i)\n");
    printf("Search for a certain dish by its code (s)\n");
    printf("Update a certain dish by its code (u)\n");
    printf("Print the entirety of Snacakroo's current database (p)\n");
    printf("Quit the program, losing all current data in the database (q)\n\n");

    // Loop until user quits
    while (1) {
        printf("Enter a command to perform: ");
        scanf(" %c", &choice);
        
        switch (choice){
            case 'i': // Insert dish 
                printf("Inserting a new dish:\n");
                int dish_inserted = insert_dish(snackaroo_database, dish_count);
                if (dish_inserted >= 0) dish_count = dish_inserted;
                break;

            case 's': // Search dish
                int search_code;
                printf("Enter dish code: ");
                
                // Scan (clear buffer and re-loop if needed)
                if (scanf("%d", &search_code) != 1) {
                    while (getchar() != '\n');
                    printf("\tYour dish code must be an integer greater or equal to 0.\n");
                    break;
                }
                getchar();
                printf("Searching for specified dish:\n");

                if (search_code < 0 || !search_dish(snackaroo_database, dish_count, search_code, 1)) {printf("\tDish code not found in Snackaroo's database.\n");}
                break;

            case 'u': // Update dish
                int code_of_update;
                printf("Enter dish code: ");

                // Scan (clear buffer and re-loop if needed)
                if (scanf("%d", &code_of_update) != 1) {
                    while (getchar() != '\n');
                    printf("\tYour dish code must be an integer greater or equal to 0.\n");
                    break;
                }

                // Update dish and print only if valid update
                if (code_of_update >= 0) {
                    int update_index = update_dish(snackaroo_database, dish_count, code_of_update);
                    if (update_index >= 0) print_dish(snackaroo_database[update_index], 1);
                } else {
                    printf("\tYour dish code must be greater or equal to 0.\n");
                }
                break;
            
            case 'p': // Print dishes
                print_dishes(snackaroo_database, dish_count);
                break;
            
            case 'q': // Quit program
                return 0;

            default:
                printf("Please enter a valid command! (i: insert a dish, s: search for a dish, u: update a dish, p: print out all dishes, q: quit program)\n");
                break;
        }
        printf("\n");
    }

}

// Insert Dish
int insert_dish(Dish database[], int total_dishes) {
    // Initialize variables
    int new_dish_code;
    char new_dish_name[100];
    char new_resteraunt_name[100];
    float new_average_customer_rating; 
    float new_price;



    // Dish Code Input
    printf("Enter your dish's code (greater or equal to 0 and not already taken): ");
    // Scan (clear buffer if needed)
    printf("test 1");
    if (scanf("%d", new_dish_code) != 1) {
        printf("test 2");
        while (getchar() != '\n');
        printf("test 3");
        printf("\tYour dish code must be an integer greater or equal to 0.\n");
        return -1; // return without adding dish at dish code input stage
    }
    getchar();

    //cd 'g:\Program Area\MS VSC Files\UWO Comp Sci Courses\C 2211 Notes and Work\Assignments\Assignment 5\output'

    // Check if reached max dishes
    if (total_dishes >= MAX_DISHES) {
        printf("\tUnfortunately, the database is full; we cannot insert your dish at this time.\n");
        return -1; // return without adding dish at dish code input stage
    } 
    // Check if invalid code
    else if (new_dish_code < 0) {
        printf("\tYour dish code must be equal or greater than 0.\n");    
        return -1; // return without adding dish at dish code input stage
    } 
    // Check if code is taken
    else if (search_dish(database, total_dishes, new_dish_code, 0)) {
        printf("\tThis dish code is already taken.\n");
        return -1; // return without adding dish at dish code input stage
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
    if (scanf("%f", &new_average_customer_rating) != 1) {
        while (getchar() != '\n');
        printf("\tYour dish rating must be an integer between 0.0 to 10.0.\n");
        return -2; // return without adding dish at dish rating input stage
    }

    // Check if rating is in range
    if (new_average_customer_rating < 0.0 || new_average_customer_rating > 10.0) {
        printf("\tYour dish's rating must be between 0.0 and 10.0.\n");
        return -2; // return without adding dish at rating input stage
    } 

    

    // Price Input
    printf("Enter your dish's price (greater than 0): ");
    if (scanf("%f", &new_price) != 1) {
        while (getchar() != '\n');
        printf("\tYour dish price must be an integer greater than 0.\n");
        return -3; // return without adding dish at dish price input stage
    }

    // Check if price is valid
    if (new_price <= 0.0) {
        printf("\tYour dish's price must be greater than 0.\n");
        return -3; // return without adding dish at price input stage
    }

    

    // Add dish to database
    database[total_dishes].dish_code = new_dish_code;
    strcpy(database[total_dishes].dish_name, new_dish_name);
    strcpy(database[total_dishes].resteraunt_name, new_resteraunt_name);
    database[total_dishes].average_customer_rating = new_average_customer_rating;
    database[total_dishes].price = new_price;

    // Increment and return total dish count
    total_dishes++;
    return total_dishes;
}

// Search Dish
int search_dish (Dish database[], int total_dishes, int dish_code, _Bool to_print_dish) {
    // Loop through database to find dish via dish code
    for (int i = 0; i < total_dishes; i++) {
        if (database[i].dish_code == dish_code) {
            if (to_print_dish) {print_dish(database[i], 1);}
            return i+1; // return index + 1 to avoid 0 return
        }
    }
    return 0;
}

// Update Dish
int update_dish(Dish database[], int total_dishes, int dish_code) {
    // Initialize variables
    int dish_index = -1;
    char updated_dish_name[100];
    char updated_resteraunt_name[100];
    float updated_average_customer_rating; 
    float updated_price;



    // Dish Code Input
    dish_index = search_dish(database, total_dishes, dish_code, 0);
    
    // Check if dish was found
    if (dish_index == 0) {
        printf("\tDish code could not be found.\n");
        return -1; // return without updating dish
    }
    getchar();
    dish_index--; // Adjusting index to match dish    
    printf("Updating existing dish (Dish #%d):\n", dish_code);


    /* The rest follows the formula in update_dish above */


    // Dish Name Input
    printf("Enter your dish's name (maximum 99 characters): "); 
    fgets(updated_dish_name, sizeof(updated_dish_name), stdin);
    if (updated_dish_name[strlen(updated_dish_name) - 1] == '\n') updated_dish_name[strlen(updated_dish_name) - 1] = '\0';



    // Resteraunt Name Input
    printf("Enter where your dish is sold (maximum 99 characters): ");
    fgets(updated_resteraunt_name, sizeof(updated_resteraunt_name), stdin);
    if (updated_resteraunt_name[strlen(updated_resteraunt_name) - 1] == '\n') updated_resteraunt_name[strlen(updated_resteraunt_name) - 1] = '\0';


    
    // Average Rating Input
    printf("Enter the average rating your dish has (from 0.0 to 10.0, inclusive): ");
    if (scanf("%f", &updated_average_customer_rating) != 1) {
        while (getchar() != '\n');
        printf("\tYour dish rating must be an integer between 0.0 to 10.0.\n");
        return -2; // return without adding dish at dish rating input stage
    }

    // Check if rating is in range
    if (updated_average_customer_rating < 0.0 || updated_average_customer_rating > 10.0) {
        printf("\tYour dish's rating must be between 0.0 and 10.0.\n");
        return -2; // return without adding dish at rating input stage
    }



    // Price Input
    printf("Enter your dish's price (greater than 0): ");
    if (scanf("%f", &updated_price) != 1) {
        while (getchar() != '\n');
        printf("\tYour dish price must be an integer greater than 0.\n");
        return -3; // return without adding dish at dish price input stage
    }

    // Check if price is valid
    if (updated_price <= 0.0) {
        printf("\tYour dish's price must be greater than 0.\n");
        return -3; // return without adding dish at price input stage
    } 



    // Update dish in database
    strcpy(database[dish_index].dish_name, updated_dish_name);
    strcpy(database[dish_index].resteraunt_name, updated_resteraunt_name);
    database[dish_index].average_customer_rating = updated_average_customer_rating;
    database[dish_index].price = updated_price;
    return dish_index;
}

// Print Dish (helper)
void print_dish(Dish dish, _Bool first_to_print) { 
    // Print header (return if empty dish)
    if (first_to_print) {
        printf("Dish Code\t");
        printf("Dish Name\t\t");
        printf("Resteraunt Name\t\t");
        printf("Dish Rating\t\t");
        printf("Dish Price\n");
        if (dish.price == 0.0) {return;}
    }

    // Print dish row
    printf("%-9d\t", dish.dish_code);
    printf("%-20s\t", dish.dish_name);
    printf("%-20s\t", dish.resteraunt_name);
    printf("%-20.1f\t\t", dish.average_customer_rating);
    printf("$%.2f\n", dish.price);
}

// Print Dishes
void print_dishes(Dish database[], int total_dishes) {
    // Print header regardless of dishes added
    Dish empty_dish = {0};
    print_dish(empty_dish, 1); 

    // Print all added dishes
    for (int i = 0; i < total_dishes; i++) {print_dish(database[i], 0);}
}
/* 
CS 2211 – Assignment 2
Name: Fardin Abbassi 
Student Number: 251446579 
Email: fabbassi@uwo.ca
Created: October 05, 2025 
--------------------------
Converts between different units based user input.
Pairs are: grams and ounces, square metres and square yards, 
litres and pints, metres and feet.
*/

#include <stdio.h>

int main() {
    // Initialize variables
    int conversion_choice, finished_selection = 0;
    float to_be_converted, converted_value, conversion_rate = 0;
    char which_conversion;

    printf("Between these options:\n");

    while (!finished_selection) {
        // Prompt for conversion choice
        printf("(1) Convert between grams and ounces\n");
        printf("(2) Convert between square metres and square yards\n");
        printf("(3) Convert between litres and pints\n");
        printf("(4) Convert between metres and feet\n");
        printf("(5) Quit\n");
        printf("What would you like to do: ");
        scanf("%d", &conversion_choice);

        // Switch between options
        switch (conversion_choice) {
            case 1: // Grams and ounces
                printf("Choose between converting from grams (G) or from ounces (O): ");
                scanf(" %c", &which_conversion);

                if (which_conversion == 'g' || which_conversion == 'G'){
                    conversion_rate = 0.03527;
                    finished_selection = 1;
                }
                else if (which_conversion == 'o' || which_conversion == 'O')
                {
                    conversion_rate = 28.3527;
                    finished_selection = 1;
                }
                else{
                    printf("Please enter a valid character!\n\n");
                    conversion_choice = 0;
                }

                break;

            case 2: // Square metres and square yards
                printf("Choose between converting from square metres (M) or from square yards (Y): ");
                scanf(" %c", &which_conversion);

                if (which_conversion == 'm' || which_conversion == 'M'){
                    conversion_rate = 1.19599;
                    finished_selection = 1;
                }
                else if (which_conversion == 'y' || which_conversion == 'Y')
                {
                    conversion_rate = 0.83613;
                    finished_selection = 1;
                }
                else{ 
                    printf("Please enter a valid character!\n\n");
                    conversion_choice = 0;
                }                break;

            case 3: // Litres and pints
                printf("Choose between converting from litres (L) or from pints (P): ");
                scanf(" %c", &which_conversion);

                if (which_conversion == 'l' || which_conversion == 'L'){
                    conversion_rate = 2.11338;
                    finished_selection = 1;
                }
                else if (which_conversion == 'p' || which_conversion == 'P')
                {
                    conversion_rate = 0.47318;
                    finished_selection = 1;
                }
                else{ 
                    printf("Please enter a valid character!\n\n");
                    conversion_choice = 0;
                }                break;

            case 4: // Metres and feet
                printf("Choose between converting from metres (M) or from feet (F): ");
                scanf(" %c", &which_conversion);

                if (which_conversion == 'm' || which_conversion == 'M'){
                    conversion_rate = 3.28084;
                    finished_selection = 1;
                }
                else if (which_conversion == 'f' || which_conversion == 'F')
                {
                    conversion_rate = 0.30480;
                    finished_selection = 1;
                }
                else{ 
                    printf("Please enter a valid character!\n\n");
                    conversion_choice = 0;
                }                break;

            case 5: // Quit program
                printf("Exiting program...\n");
                return 0;

            default: // Any other integer (loop back)
                printf("Please enter a valid integer!\n\n");
                break;
        }
    }

    // Prompt and print conversion, then exit
    printf("Please enter your value: ");
    scanf("%f", &to_be_converted);

    converted_value = to_be_converted * conversion_rate;
    printf("Your conversion is %.5f\n", converted_value);
    return 0;
}
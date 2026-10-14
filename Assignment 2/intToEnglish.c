/*
CS 2211 – Assignment 2
Name: Fardin Abbassi
Student Number: 251446579
Email: fabbassi@uwo.ca
Created: October 05, 2025
--------------------------
Converts an integer between 1-999 into English words
*/

#include <stdio.h>

int main() {
    // Initialize variables
    int int_to_convert, teens = 0;

    // Loop until quit
    while (1) {
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &int_to_convert);
    
        // Begin printing the number in English
        printf("You entered the number ");

        // Exit on 0
        if (int_to_convert == 0) break;

        
        // Hundreds
        if (int_to_convert / 100 > 0) {
            switch (int_to_convert / 100) {
                case 1:
                    printf("one ");
                    break;
                case 2:
                    printf("two ");
                    break;
                case 3:
                    printf("three ");
                    break;
                case 4:
                    printf("four ");
                    break;
                case 5:
                    printf("five ");
                    break;
                case 6:
                    printf("six ");
                    break;
                case 7:
                    printf("seven ");
                    break;
                case 8:
                    printf("eight ");
                    break;
                case 9:
                    printf("nine ");
                    break;
            }
            printf("hundred ");

            // Move onto tens, check if we need more prints
            int_to_convert = int_to_convert % 100;
            if (int_to_convert > 0) printf("and ");
        }

        // Tens
        if (int_to_convert / 10 > 0) {
            switch (int_to_convert / 10) {
                case 2:
                    printf("twenty-");
                    break;
                case 3:
                    printf("thirty-");
                    break;
                case 4:
                    printf("fourty-");
                    break;
                case 5:
                    printf("fifty-");
                    break;
                case 6:
                    printf("sixty-");
                    break;
                case 7:
                    printf("seventy-");
                    break;
                case 8:
                    printf("eighty-");
                    break;
                case 9:
                    printf("ninety-");
                    break;
            }
            
            // Move onto ones, check if we need to handle teens
            if (int_to_convert <= 19 && int_to_convert >= 10) { teens = 1; }
            int_to_convert = int_to_convert % 10;
        }
        
        // Ones and teens
        if (teens) {
            switch (int_to_convert) {
                case 0:
                    printf("ten");
                    break;
                case 1:
                    printf("eleven");
                    break;
                case 2:
                    printf("twelve");
                    break;
                case 3:
                    printf("thirteen");
                    break;
                case 4:
                    printf("fourteen");
                    break;
                case 5:
                    printf("fifteen");
                    break;
                case 6:
                    printf("sixteen");
                    break;
                case 7:
                    printf("seventeen");
                    break;
                case 8:
                    printf("eighteen");
                    break;
                case 9:
                    printf("nineteen");
                    break;
            }
            teens = 0;
        }
        else {
            switch (int_to_convert) {
                case 0:
                    printf("\b \b"); // doesnt erase be
                    break;
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
            }
        }
    
        // Print newline
        printf("\n");
    }
    
    // Exit
    printf("zero\nExiting program...");
    return 0;
}
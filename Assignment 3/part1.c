#include <stdio.h>

// Print array in regular order
void partOne(int n, int arr[]) {
    printf("Your array is: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] = %d", i, arr[i]);
        if (i != n-1) {printf(", ");}
    }
    printf("\n");
}

// Print array in reverse order
void partTwo(int n, int arr[]) {
    printf("Your array in reverse is: ");
    for (int i = n-1; i >= 0; i--) {
        printf("[%d] = %d", i, arr[i]);
        if (i != 0) {printf(", ");}
    }
    printf("\n");
}

// Print even numbers from array
void partThree(int n, int arr[]) {
    printf("The even elements in the array is: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("[%d] = %d", i, arr[i]);
            if (i < n-1) {printf(", ");} // Technically doesn't print as expected, since there'll be a trailing comma
        }
    }
    printf("\n");
}

// Sum up all values of the array
void partFour(int n, int arr[]) {
    printf("The sum of all values in your array is: ");
    int sum = 0;
    for (int i = 0; i < n; i++) {sum += arr[i];}
    printf("%d\n", sum);
}

// Print elements from lowest to highest value
void partFive(int n, int arr[]) {
    // Initialize index and finished array to track printed values
    int smallIndex;
    int finished[n];
    for (int i = 0; i < n; i++) { finished[i] = 0;}
    printf("Your array in sorted order is: ");

    // Loop until all values are printed
    for (int i = 0; i < n; i++) {
        // Loop to find smallest value
        smallIndex = 0;
        for (int j = 0; j < n; j++) {
            if (finished[j] == 1) {continue;} // Skip already printed values
            else if (arr[j] < arr[smallIndex]) {smallIndex = j;} // Check for smaller value if not handled already
        }
        
        // Print smallest unprinted value, then mark as printed
        printf("[%d] = %d", smallIndex, arr[smallIndex]);
        if (i < n-1) {printf(", ");}
        finished[smallIndex] = 1;
    }
    printf("\n");
}

// Print array, switching first and last indexes
void partSix(int n, int arr[]) {
    printf("Your array with first and last element switched is: ");

    printf("[%d] = %d, ", (n-1), arr[n-1]); // Last index printed first
    for (int i = 1; i < n-1; i++) {printf("[%d] = %d, ", i, arr[i]);} // Middle indices printed the same
    printf("[%d] = %d\n", 0, arr[0]); // First index printed last
}

int main() {
    // Initialize variable
    int n;

    // Scan for number of integers
    printf("Please enter the number of integers to process: ");
    scanf("%d", &n);

    // Set array size based on user input
    int arr[n]; 
    

    // Print size of array in bytes
    printf("There is enough room in your array for %d integers (%lu bytes)\n", n, sizeof(arr));

    // Scan for integers
    printf("Please enter your integers separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    // Call each part function, then exit program
    printf("Part 1:\n\t");
    partOne(n, arr);

    printf("Part 2:\n\t");
    partTwo(n, arr);

    printf("Part 3:\n\t");
    partThree(n, arr);

    printf("Part 4:\n\t");
    partFour(n, arr);

    printf("Part 5:\n\t");
    partFive(n, arr);

    printf("Part 6:\n\t");
    partSix(n, arr);
    return 0;
}
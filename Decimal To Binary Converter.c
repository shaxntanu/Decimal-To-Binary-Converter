#include <stdio.h>
#include <stdlib.h>

void decimalToBinary64(unsigned long long n) {
    int i;
    int started = 0; // flag to ignore leading zeros

    if (n == 0) {
        printf("0");
        return;
    }

    for (i = 63; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 1) {
            started = 1;
        }
        if (started) {
            printf("%d", bit);
        }
    }
    printf("\n");
}

int main() {
    char choice = 'Y';

    printf("Welcome to the Decimal to Binary Converter!\n");

    while (choice == 'Y' || choice == 'y') {
        unsigned long long decimalNumber;
        int validInput;

        printf("\nPlease enter the decimal number which needs to be converted:\n");

        // Input validation loop
        while (1) {
            validInput = scanf("%llu", &decimalNumber);

            if (validInput == 1) {
                break; // valid input received, exit loop
            } else {
                printf("Invalid input! Please enter a valid unsigned integer:\n");

                // Clear invalid input from buffer
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
            }
        }

        printf("Here is your binary number:\n");
        decimalToBinary64(decimalNumber);

        // Ask if user wants to convert another number
        printf("\nDo you want to convert another number? (Y/N): ");
        // Consume newline left by scanf
        while ((getchar()) != '\n');

        choice = getchar();
        // Consume newline after character input
        while ((getchar()) != '\n');

        if (choice == 'N' || choice == 'n') {
            printf("\nThank you for using the converter! Made by Shantanu.\n");
        } else if (choice != 'Y' && choice != 'y') {
            printf("\nInvalid choice. Exiting the program.\n");
            break;
        }
    }

    return 0;
}

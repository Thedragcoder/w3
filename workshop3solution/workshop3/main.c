#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "main.h"


int main() {
    struct Customer customer;

    printf("Enter customer information:\n");
    customer = inputCustomerInfo();

    printf("\nYou entered:\n");
    printf("First Name: %s\n", customer.firstName);
    printf("Last Name: %s\n", customer.lastName);
    printf("Street Address: %s\n", customer.streetAddress);
    printf("City: %s\n", customer.city);
    printf("Province: %s\n", customer.province);
    printf("Postal Code: %s\n", customer.postalCode);


    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Funcgion to validate province
bool isValidProvince(const char* province) {
    int len;
    len = strlen(province);
    if (len < 2) {
        return false;
    }
    else {
        return true;
    }
    for (int i = 0; i < 2; i++) {
        if (!isdigit(province[i])) { // Check if each character is number or not
            return false;
        }
    }
}

// Function to validate a postal code
bool isValidPostalCode(const char* code) {
    // Remove spaces and extra spaces from the input
    char formattedCode[50];
    int j = 0; // Index for formattedCode

    for (int i = 0; code[i] != '\0'; i++) {
        if (!isspace(code[i])) { // Ignore spaces
            formattedCode[j++] = toupper(code[i]); // Convert to uppercase and copy
        }
    }
    formattedCode[j] = '\0'; // Null-terminate the formatted code

    // Check if the formatted code is valid
    if (strlen(formattedCode) != 6) // Postal code should be 6 characters long
        return false;

    for (int i = 0; i < 6; i++) {
        if (!isalnum(formattedCode[i])) // Check if each character is alphanumeric
            return false;
        if (i % 2 == 0 && !isalpha(formattedCode[i])) // Alternating characters should be alphabetic
            return false;
        if (i % 2 != 0 && !isdigit(formattedCode[i])) // Alternating characters should be numeric
            return false;
    }

    return true;
}

// Function to input customer information
struct Customer inputCustomerInfo() {
    struct Customer customer;

    do {
        printf("Enter your first name: ");
        fgets(customer.firstName, 50, stdin);
        if (strlen(customer.firstName) < 2) {
            printf("Invalid Entry:");
        }
    } while (strlen(customer.firstName) < 2); // Keep prompting until a non-empty value is entered

    do {
        printf("Enter your last name: ");
        fgets(customer.lastName, 50, stdin);
        if (strlen(customer.lastName) < 2) {
            printf("Invalid Entry:");
        }
    } while (strlen(customer.lastName) < 2); // Keep prompting until a non-empty value is entered

    do {
        printf("Enter your street address: ");
        fgets(customer.streetAddress, 100, stdin);
        if (strlen(customer.streetAddress) < 2) {
            printf("Invalid Entry:");
        }
    } while (strlen(customer.streetAddress) < 2); // Keep prompting until a non-empty value is entered

    do {
        printf("Enter your city: ");
        fgets(customer.city, 50, stdin);
        if (strlen(customer.city) < 2) {
            printf("Invalid Entry:");
        }
    } while (strlen(customer.city) < 2); // Keep prompting until a non-empty value is entered

    do {
        printf("Enter your province: ");
        fgets(customer.province, 3, stdin);
        clearInputBuffer();
        if (!isValidProvince(customer.province)) {
            printf("Invalid Entry:");
        }
    } while (!isValidProvince(customer.province)); // Keep prompting until a non-empty value is entered

    do {
        printf("Enter your postal code: ");
        fgets(customer.postalCode, 50, stdin);
        clearInputBuffer();
        if (!isValidPostalCode(customer.postalCode))
        {
            printf("Invalid Entry:");
        }
    } while (!isValidPostalCode(customer.postalCode)); // Keep prompting until a valid postal code is entered

    return customer;
}
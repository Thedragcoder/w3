
// Define a structure to store customer information
struct Customer {
    char firstName[50];
    char lastName[50];
    char streetAddress[100];
    char city[50];
    char province[50];
    char postalCode[50];
};


bool isValidPostalCode(const char* code);
struct Customer inputCustomerInfo();
bool isValidProvince(const char* province);
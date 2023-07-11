#include <iostream>
#include <fstream>
#include <string>

struct Customer {
    int accountNumber;
    std::string firstName;
    std::string lastName;
    double balance;
};

void createCustomerFile() {
    std::ofstream outputFile("customer_records.txt");
    if (!outputFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    Customer customers[5];

    // Enter customer records
    for (int i = 0; i < 5; i++) {
        customers[i].accountNumber = 1000 + i;

        std::cout << "Enter the first name for customer " << customers[i].accountNumber << ": ";
        std::cin >> customers[i].firstName;

        std::cout << "Enter the last name for customer " << customers[i].accountNumber << ": ";
        std::cin >> customers[i].lastName;

        std::cout << "Enter the account balance for customer " << customers[i].accountNumber << ": ";
        std::cin >> customers[i].balance;

        outputFile << customers[i].accountNumber << " "
                   << customers[i].firstName << " "
                   << customers[i].lastName << " "
                   << customers[i].balance << std::endl;
    }

    outputFile.close();
}

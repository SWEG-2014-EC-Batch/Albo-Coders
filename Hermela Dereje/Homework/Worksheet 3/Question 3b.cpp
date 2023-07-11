#include <iostream>
#include <fstream>
#include <string>

struct Customer {
    int accountNumber;
    std::string firstName;
    std::string lastName;
    double balance;
};

Customer getCustomerInfo(const std::string& fileName, int accountNumber) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return Customer();
    }

    Customer customer;
    while (inputFile >> customer.accountNumber >> customer.firstName >> customer.lastName >> customer.balance) {
        if (customer.accountNumber == accountNumber) {
            inputFile.close();
            return customer;
        }
    }

    inputFile.close();
    return Customer();
}

int main() {
    createCustomerFile();

    std::string fileName = "customer_records.txt";
    int accountNumber;

    std::cout << "Enter an account number: ";
    std::cin >> accountNumber;

    Customer customer = getCustomerInfo(fileName, accountNumber);

    if (customer.accountNumber == 0) {
        std::cout << "Customer not found!" << std::endl;
    } else {
        std::cout << "Account Number: " << customer.accountNumber << std::endl;
        std::cout << "Name: " << customer.firstName << " " << customer.lastName << std::endl;
        std::cout << "Balance: $" << customer.balance << std::endl;
    }

    return 0;
}

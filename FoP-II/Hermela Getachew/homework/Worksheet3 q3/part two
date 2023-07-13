#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Implement the program to retrieve customer information based on the account number

struct Customer {
    int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

Customer getCustomerInfo(const string& fileName, int accountNumber) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error opening file: " << fileName << endl;
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

    string fileName = "customer_records.txt";
    int accountNumber;

    cout << "Enter an account number: ";
    cin >> accountNumber;

    Customer customer = getCustomerInfo(fileName, accountNumber);

    if (customer.accountNumber == 0) {
        cout << "Customer not found!" << endl;
    } else {
        cout << "Account Number: " << customer.accountNumber << endl;
        cout << "Name: " << customer.firstName << " " << customer.lastName <<endl;
        cout << "Balance: $" << customer.balance <<endl;
    }

    return 0;
}

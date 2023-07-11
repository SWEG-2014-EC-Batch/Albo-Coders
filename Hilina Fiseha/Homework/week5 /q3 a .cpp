#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Customer {
    int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

void createCustomerFile() {
    ofstream outputFile("customer_records.txt");
    if (!outputFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    Customer customers[5];

    // Enter customer records
    for (int i = 0; i < 5; i++) {
        customers[i].accountNumber = 1000 + i;

        cout << "Enter the first name for customer " << customers[i].accountNumber << ": ";
        cin >> customers[i].firstName;

        cout << "Enter the last name for customer " << customers[i].accountNumber << ": ";
        cin >> customers[i].lastName;

        cout << "Enter the account balance for customer " << customers[i].accountNumber << ": ";
        cin >> customers[i].balance;

        outputFile << customers[i].accountNumber << " "
                   << customers[i].firstName << " "
                   << customers[i].lastName << " "
                   << customers[i].balance << endl;
    }

    outputFile.close();
}

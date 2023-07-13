#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int NUM_EMPLOYEES = 10;

struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

void enterEmployeeData(Employee employees[]) {
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Enter data for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Sex (M/F): ";
        cin >> employees[i].sex;
        cout << "Hourly Wage: ";
        cin >> employees[i].hourlyWage;
        cout << "Years with the company: ";
        cin >> employees[i].yearsWithCompany;
    }
}

void sortEmployeesById(Employee employees[]) {
    sort(employees, employees + NUM_EMPLOYEES, [](Employee a, Employee b) {
        return a.id < b.id;
    });
}

void writeEmployeeDataToFile(Employee employees[], const string& fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        outFile << employees[i].id << " " << employees[i].sex << " " << employees[i].hourlyWage << " " << employees[i].yearsWithCompany << endl;
    }

    outFile.close();
}

void readEmployeeDataFromFile(Employee employees[], const string& fileName) {
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        inFile >> employees[i].id >> employees[i].sex >> employees[i].hourlyWage >> employees[i].yearsWithCompany;
    }

    inFile.close();
}

void calculatePayForMonth(Employee employees[]) {
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        double hoursWorked;
        cout << "Enter number of hours worked by employee " << employees[i].id << ": ";
        cin >> hoursWorked;

        double totalPay = hoursWorked * employees[i].hourlyWage;
        cout << "Total pay for employee " << employees[i].id << " this month is: $" << totalPay << endl;
    }
}

void updateEmployeeData(Employee employees[]) {
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        char choice;
        cout << "Do you want to update hourly wage and years of service for employee " << employees[i].id << "? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "Enter new hourly wage for employee " << employees[i].id << ": ";
            cin >> employees[i].hourlyWage;
            cout << "Enter new years of service for employee " << employees[i].id << ": ";
            cin >> employees[i].yearsWithCompany;
        }
    }
}

void writeUpdatedEmployeeDataToFile(Employee employees[], const string& fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        outFile << employees[i].id << " " << employees[i].sex << " " << employees[i].hourlyWage << " " << employees[i].yearsWithCompany << endl;
    }

    outFile.close();
}

int main() {
    Employee employees[NUM_EMPLOYEES];
    enterEmployeeData(employees);

    sortEmployeesById(employees);

    string fileName = "employee_data.txt";
    writeEmployeeDataToFile(employees, fileName);

    // read employee data from file and calculate pay for the month
    Employee employeesFromFile[NUM_EMPLOYEES];
    readEmployeeDataFromFile(employeesFromFile, fileName);
    calculatePayForMonth(employeesFromFile);

    // update employee data and write to new file
    updateEmployeeData(employeesFromFile);
    string updatedFileName = "updated_employee_data.txt";
    writeUpdatedEmployeeDataToFile(employeesFromFile, updatedFileName);

    return 0;
}

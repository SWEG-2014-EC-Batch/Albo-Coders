#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

double calculateTotalPay(const Employee& emp, double hoursWorked) {
    double overtimeRate = 1.5;
    double overtimeThreshold = 40.0;
    double totalPay = emp.hourlyWage * hoursWorked;

    if (hoursWorked > overtimeThreshold) {
        double overtimeHours = hoursWorked - overtimeThreshold;
        double overtimePay = overtimeRate * emp.hourlyWage * overtimeHours;
        totalPay += overtimePay;
    }

    return totalPay;
}

int main() {
    ifstream inputFile("employee_records.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<Employee> employees;
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;

    // Read employee records from the file
    while (inputFile >> id >> sex >> hourlyWage >> yearsWithCompany) {
        Employee emp;
        emp.id = id;
        emp.sex = sex;
        emp.hourlyWage = hourlyWage;
        emp.yearsWithCompany = yearsWithCompany;
        employees.push_back(emp);
    }

    inputFile.close();

    double hoursWorked;
    for (const Employee& emp : employees) {
        cout << "Enter the number of hours worked by employee " << emp.id << ": ";
        cin >> hoursWorked;

        double totalPay = calculateTotalPay(emp, hoursWorked);
        cout << "Total pay for employee " << emp.id << ": $" << totalPay << endl;
    }

    return 0;
}

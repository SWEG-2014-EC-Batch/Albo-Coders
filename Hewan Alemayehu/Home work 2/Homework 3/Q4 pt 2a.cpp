//Part 2a: Calculating total pay for each employee based on hours worked.
#include <iostream>
#include <fstream>
#include <vector>

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
    std::ifstream inputFile("employee_records.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<Employee> employees;
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
        std::cout << "Enter the number of hours worked by employee " << emp.id << ": ";
        std::cin >> hoursWorked;

        double totalPay = calculateTotalPay(emp, hoursWorked);
        std::cout << "Total pay for employee " << emp.id << ": $" << totalPay << std::endl;
    }

    return 0;
}

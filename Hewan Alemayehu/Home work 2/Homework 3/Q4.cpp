// Part 1: Writing the employee records to a file and sorting them by ID number.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

// Comparator function to sort employees by ID number
bool compareByID(const Employee& emp1, const Employee& emp2) {
    return emp1.id < emp2.id;
}

void writeEmployeeRecords() {
    std::ofstream outputFile("employee_records.txt");
    if (!outputFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    std::vector<Employee> employees;

    // Enter employee records
    for (int i = 0; i < 10; i++) {
        Employee emp;

        std::cout << "Enter ID for employee " << i + 1 << ": ";
        std::cin >> emp.id;

        std::cout << "Enter sex (M/F) for employee " << i + 1 << ": ";
        std::cin >> emp.sex;

        std::cout << "Enter hourly wage for employee " << i + 1 << ": ";
        std::cin >> emp.hourlyWage;

        std::cout << "Enter years with the company for employee " << i + 1 << ": ";
        std::cin >> emp.yearsWithCompany;

        employees.push_back(emp);
    }

    // Sort employees by ID number
    std::sort(employees.begin(), employees.end(), compareByID);

    // Write sorted records to the file
    for (const Employee& emp : employees) {
        outputFile << emp.id << " " << emp.sex << " " << emp.hourlyWage << " " << emp.yearsWithCompany << std::endl;
    }

    outputFile.close();
}


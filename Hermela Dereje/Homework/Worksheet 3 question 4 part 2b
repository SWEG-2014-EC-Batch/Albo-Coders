#include <iostream>
#include <fstream>
#include <vector>

struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

void updateEmployeeRecords() {
    std::ifstream inputFile("employee_records.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::ofstream outputFile("updated_employee_records.txt");
    if (!outputFile) {
        std::cerr << "Error creating file!" << std::endl;
        inputFile.close();
        return;
    }

    std::vector<Employee> employees;
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;

    // Read employee records from the file and update information
    while (inputFile >> id >> sex >> hourlyWage >> yearsWithCompany) {
        Employee emp;
        emp.id = id;
        emp.sex = sex;

        // Modify hourly wage or years of service based on your requirement
        emp.hourlyWage = hourlyWage * 1.1;  // Increase hourly wage by 10%
        emp.yearsWithCompany = yearsWithCompany + 1;  // Increment years of service by 1

        employees.push_back(emp);

        // Write updated record to the file
        outputFile << emp.id << " " << emp.sex << " " << emp.hourlyWage << " " << emp.yearsWithCompany << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

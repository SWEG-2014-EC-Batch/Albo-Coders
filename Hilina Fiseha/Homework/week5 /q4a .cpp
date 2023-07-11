#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
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
    ofstream outputFile("employee_records.txt");
    if (!outputFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    vector<Employee> employees;

    // Enter employee records
    for (int i = 0; i < 10; i++) {
        Employee emp;

        cout << "Enter ID for employee " << i + 1 << ": ";
        cin >> emp.id;

        cout << "Enter sex (M/F) for employee " << i + 1 << ": ";
        cin >> emp.sex;

        cout << "Enter hourly wage for employee " << i + 1 << ": ";
        cin >> emp.hourlyWage;

        cout << "Enter years with the company for employee " << i + 1 << ": ";
        cin >> emp.yearsWithCompany;

        employees.push_back(emp);
    }

    // Sort employees by ID number
    sort(employees.begin(), employees.end(), compareByID);

    // Write sorted records to the file
    for (const Employee& emp : employees) {
        outputFile << emp.id << " " << emp.sex << " " << emp.hourlyWage << " " << emp.yearsWithCompany << endl;
    }

    outputFile.close();
}

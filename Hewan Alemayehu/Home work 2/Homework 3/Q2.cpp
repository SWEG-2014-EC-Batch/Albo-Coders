#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

struct Employee {
    std::string name;
    double payRate;
    double hoursWorked;
    double regularPay;
    double overtimePay;
    double grossPay;
};

void generatePayReport(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::cout << "Pay Report" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(10) << "Pay Rate"
              << std::setw(10) << "Hours"
              << std::setw(15) << "Regular Pay"
              << std::setw(15) << "Overtime Pay"
              << std::setw(10) << "Gross Pay" << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    Employee employee;
    double totalRegularPay = 0.0;
    double totalOvertimePay = 0.0;
    double totalGrossPay = 0.0;

    while (inputFile >> employee.name >> employee.payRate >> employee.hoursWorked) {
        if (employee.hoursWorked <= 40.0) {
            employee.regularPay = employee.hoursWorked * employee.payRate;
            employee.overtimePay = 0.0;
        } else {
            employee.regularPay = 40.0 * employee.payRate;
            employee.overtimePay = (employee.hoursWorked - 40.0) * employee.payRate * 1.5;
        }

        employee.grossPay = employee.regularPay + employee.overtimePay;

        totalRegularPay += employee.regularPay;
        totalOvertimePay += employee.overtimePay;
        totalGrossPay += employee.grossPay;

        std::cout << std::left << std::setw(15) << employee.name
                  << std::setw(10) << employee.payRate
                  << std::setw(10) << employee.hoursWorked
                  << std::setw(15) << employee.regularPay
                  << std::setw(15) << employee.overtimePay
                  << std::setw(10) << employee.grossPay << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Totals:"
              << std::setw(15) << ""
              << std::setw(10) << ""
              << std::setw(10) << ""
              << std::setw(15) << totalRegularPay
              << std::setw(15) << totalOvertimePay
              << std::setw(10) << totalGrossPay << std::endl;

    inputFile.close();
}

int main() {
    std::string fileName = "employee_data.txt";

    generatePayReport(fileName);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

struct Employee {
    string name;
    double payRate;
    double hoursWorked;
    double regularPay;
    double overtimePay;
    double grossPay;
};

void generatePayReport(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    cout << "Pay Report" << endl;
    cout << "-------------------------------------" << endl;
    cout << left << setw(15) << "Name"
              << setw(10) << "Pay Rate"
              << setw(10) << "Hours"
              << setw(15) << "Regular Pay"
              << setw(15) << "Overtime Pay"
              << setw(10) << "Gross Pay" << endl;

    cout << fixed << setprecision(2);

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

        cout << left << setw(15) << employee.name
                  << setw(10) << employee.payRate
                  << setw(10) << employee.hoursWorked
                  << setw(15) << employee.regularPay
                  << setw(15) << employee.overtimePay
                  << setw(10) << employee.grossPay << endl;
    }

    cout << "-------------------------------------" << endl;
    cout << "Totals:"
              << setw(15) << ""
              << setw(10) << ""
              << setw(10) << ""
              << setw(15) << totalRegularPay
              << setw(15) << totalOvertimePay
              << setw(10) << totalGrossPay << endl;

    inputFile.close();
}

int main() {
    string fileName = "employee_data.txt";

    generatePayReport(fileName);

    return 0;
}

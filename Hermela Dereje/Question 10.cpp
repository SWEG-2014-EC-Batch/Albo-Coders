#include <iostream>
using namespace std;
void inputLength(int& feet, int& inches) {
    cout << "Enter the length in feet: ";
    cin >> feet;

    cout << "Enter the length in inches: ";
    cin >> inches;
}

void convertToMetric(int feet, int inches, int& meters, int& centimeters) {
    double totalInches = (feet * 12) + inches;
    double totalCentimeters = totalInches * 2.54;

    meters = totalCentimeters / 100;
    centimeters = static_cast<int>(totalCentimeters) % 100;
}

void outputLength(int feet, int inches, int meters, int centimeters) {
    cout << "Length in feet and inches: " << feet << "ft " << inches << "in" << endl;
    cout << "Length in meters and centimeters: " << meters << "m " << centimeters << "cm" << endl;
}

int main() {
    char repeat;

    do {
        int feet, inches;
        int meters, centimeters;

        inputLength(feet, inches);
        convertToMetric(feet, inches, meters, centimeters);
        outputLength(feet, inches, meters, centimeters);

        cout << "Do you want to calculate again? (Y/N): ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}ela Dereje/Homework/Question 10.cpp

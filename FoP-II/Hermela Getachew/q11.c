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

void convertToImperial(int meters, int centimeters, int& feet, int& inches) {
    double totalCentimeters = (meters * 100) + centimeters;
    double totalInches = totalCentimeters / 2.54;

    feet = totalInches / 12;
    inches = static_cast<int>(totalInches) % 12;
}

void outputLength(int feet, int inches, int meters, int centimeters) {
    cout << "Length in feet and inches: " << feet << "ft " << inches << "in" << endl;
    cout << "Length in meters and centimeters: " << meters << "m " << centimeters << "cm" << endl;
}

int main() {
    char repeat;

    do {
        int choice;
        int feet, inches;
        int meters, centimeters;

        cout << "Choose the conversion type:\n";
        cout << "1. Feet and inches to meters and centimeters\n";
        cout << "2. Meters and centimeters to feet and inches\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        if (choice == 1) {
            inputLength(feet, inches);
            convertToMetric(feet, inches, meters, centimeters);
            outputLength(feet, inches, meters, centimeters);
        } else if (choice == 2) {
            inputLength(meters, centimeters);
            convertToImperial(meters, centimeters, feet, inches);
            outputLength(feet, inches, meters, centimeters);
        } else {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Do you want to perform another conversion? (Y/N): ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

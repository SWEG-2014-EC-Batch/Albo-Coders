#include <iostream>
using namespace std;
struct phone {
    double areaCode;
    double exchange;
    double number;
};

void displayPhoneNumber(const phone& p) {
    cout << "(" << p.areaCode << ")" << p.exchange << "-" << p.number << endl;
}

int main() {
    int numPhoneNumbers;

    cout << "Enter the number of phone numbers: ";
    cin >> numPhoneNumbers;

    // Create an array of phone structures
    phone phoneNumbers[numPhoneNumbers];



    cout << "Enter the phone numbers:" << endl;

    for (int i = 0; i < numPhoneNumbers; ++i) {
        cout << "Phone Number " << (i + 1) << ":" << endl;

        cout << "Area Code: ";
        cin >> phoneNumbers[i].areaCode;

        cout << "Exchange: ";
        cin >> phoneNumbers[i].exchange;

        cout << "Number: ";
        cin >> phoneNumbers[i].number;

        cout << endl;
    }

    cout << endl;

    cout << "Phone Numbers:" << endl;

    // Display all phone numbers
    cout << "Phone Number 1: ";


    for (int i = 0; i < numPhoneNumbers; ++i) {
        cout << "Phone Number " << (i + 2) << ": ";
        displayPhoneNumber(phoneNumbers[i]);
    }

    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct phone {
    double areaCode;
    double exchange;
    double number;
};

struct person {
    string name;
    phone phoneNumber;
};

void displayPhoneNumber(const phone& p) {
    cout << "(" << p.areaCode << ")" << p.exchange << "-" << p.number << endl;
}

void displayPerson(const person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Phone Number: ";
    displayPhoneNumber(p.phoneNumber);
}

int main() {
    const int NUM_PERSONS = 10;
    person persons[NUM_PERSONS];

    cout << "Enter the names and phone numbers of " << NUM_PERSONS << " persons:" << endl;

    for (int i = 0; i < NUM_PERSONS; ++i) {
        cout << "Person " << (i + 1) << ":" << endl;

        cout << "Name: ";
        cin >> persons[i].name;

        cout << "Area Code: ";
        cin >> persons[i].phoneNumber.areaCode;

        cout << "Exchange: ";
        cin >> persons[i].phoneNumber.exchange;

        cout << "Number: ";
        cin >> persons[i].phoneNumber.number;

        cout << endl;
    }

    cout << endl;

    cout << "Phone Numbers:" << endl;

    for (int i = 0; i < NUM_PERSONS; ++i) {
        cout << "Person " << (i + 1) << ":" << endl;
        displayPerson(persons[i]);
        cout << endl;
    }

    return 0;
}

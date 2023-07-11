#include <iostream>
using namespace std;

struct Phone {
    int areaCode;
    int exchange;
    int number;
};

void printPhone(Phone p) {
    cout << "(" << p.areaCode << ") " << p.exchange << "-" << p.number << endl;
}

int main() {
    Phone p1 = {212, 767, 8900};
    Phone p2;

    cout << "Enter a phone number (area code exchange number): ";
    cin >> p2.areaCode >> p2.exchange >> p2.number;

    cout << "Phone 1: ";
    printPhone(p1);
    cout << "Phone 2: ";
    printPhone(p2);

    return 0;
}

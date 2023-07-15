#include <iostream>
using namespace std;
// leap year with function
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    }
    return false;
}

bool isValidDate(int day, int month, int year) {
    if (month < 1  month > 12) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    if (day < 1  day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

void printLeapYears(int year) {
    int leapYears[20];
    int count = 0;

    while (count < 20) {
        year++;
        if (isLeapYear(year)) {
            leapYears[count] = year;
            count++;
        }
    }
cout << "Here are the next twenty leap years: ";
    for (int i = 0; i < 20; ++i) {
        cout << leapYears[i];
        if (i != 19) {
            cout << ", ";
        }
    }
    cout << endl;
}


int main() {
    int day, month, year;

    while (true) {
        cout << "Please enter a date (dd mm yyyy): ";
        cin >> day >> month >> year;

        if (!isValidDate(day, month, year)) {
            if (month < 1 || month > 12) {
                cout << "Invalid month: " << month << endl;
            } else {
                cout << "Invalid day of month " << day << endl;
            }
        } else {
            cout << day << "/" << month << "/" << year << " is a valid date";
            if (isLeapYear(year)) {
                cout << " and also a Leap Year" << endl;
                printLeapYears(year);
            } else {
                cout << " but not a Leap Year" << endl;
            }
        }

        cout << endl;
    }

    return 0;
}































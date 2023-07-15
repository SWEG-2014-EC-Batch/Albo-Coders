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

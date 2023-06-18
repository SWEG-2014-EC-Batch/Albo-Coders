include <iostream>
using namespace std;
void getTime(int& hours, int& minutes) {
    cout << "Enter the time in 24-hour notation (hh:mm): ";
    cin >> hours >> minutes;
}

void convertTime(int& hours, int& minutes, char& amPm) {
    if (hours >= 12) {
        amPm = 'P';
        if (hours > 12)
            hours -= 12;
    } else {
        amPm = 'A';
        if (hours == 0)
            hours = 12;
    }
}

void printTime(int hours, int minutes, char amPm) {
    cout << "The time in 12-hour notation is: " << hours << ":";

    if (minutes < 10)
        cout << "0"; // Leading zero for single-digit minutes

    cout << minutes << " ";

    if (amPm == 'A')
        cout << "AM";
    else
        cout << "PM";

    cout << endl;
}

int main() {
    char choice;

    do {
        int hours, minutes;
        char amPm;

        getTime(hours, minutes);
        convertTime(hours, minutes, amPm);
        printTime(hours, minutes, amPm);

        cout << "Do you want to convert another time? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');

    return 0;
}

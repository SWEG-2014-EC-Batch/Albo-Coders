#include <iostream>
#include <iomanip>
#include <string>
// rain fall with function
using namespace std;

const int NUM_MONTHS = 12;
const string MONTH_NAMES[NUM_MONTHS] = {"Meskerem", "Tikimt", "Hidar", "Tahsas", "Tir", "Yekatit", "Megabit", "Miazia", "Genbot", "Sene", "Hamle", "Nehase"};

void printTable(const double avgRainfall[], const double actualRainfall[]) {
    cout << setw(10) << "Month" << setw(20) << "Avg. Rainfall (mm)" << setw(20) << "Actual Rainfall (mm)" << setw(20) << "Diff. (mm)" << endl;
    for (int i = 0; i < NUM_MONTHS; i++) {
        double diff = actualRainfall[i] - avgRainfall[i];
        cout << setw(10) << MONTH_NAMES[i] << setw(20) << avgRainfall[i] << setw(20) << actualRainfall[i] << setw(20) << diff << endl;
    }
}

void printBarGraph(const double avgRainfall[], const double actualRainfall[]) {
    cout << "Average Rainfall (mm) | Actual Rainfall (mm)" << endl;
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << setw(10) << MONTH_NAMES[i] << " | ";
        for (int j = 0; j < 2; j++) {
            double rainfall = (j == 0) ? avgRainfall[i] : actualRainfall[i];
            int numStars = static_cast<int>(rainfall / 10.0);
            for (int k = 0; k < numStars; k++) {
                cout << "*";
            }
            cout << " | ";
        }
        cout << endl;
    }
}

int main() {
    double avgRainfall[NUM_MONTHS];
    double actualRainfall[NUM_MONTHS];
    int currentMonth;
    cout << "Enter the average monthly rainfall for Addis Ababa city for each month of the year:" << endl;
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << MONTH_NAMES[i] << ": ";
        cin >> avgRainfall[i];
    }
cout << "Enter the current month (1-12): ";
    cin >> currentMonth;
    cout << "Enter the actual monthly rainfall for each of the previous 12 months:" << endl;
    for (int i = 0; i < NUM_MONTHS; i++) {
        int monthIndex = (currentMonth - i - 1 + NUM_MONTHS) % NUM_MONTHS;
        cout << MONTH_NAMES[monthIndex] << ": ";
        cin >> actualRainfall[monthIndex];
    }
while (true) {
        cout << "Do you want to see the table or the bar graph? (t/b/q): ";
        char choice;
        cin >> choice;
        if (choice == 't') {
            printTable(avgRainfall, actualRainfall);
        } else if (choice == 'b') {
            printBarGraph(avgRainfall, actualRainfall);
        } else if (choice == 'q') {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

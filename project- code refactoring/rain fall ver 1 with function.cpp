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

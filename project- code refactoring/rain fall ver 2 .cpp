#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;
const string MONTHS[NUM_MONTHS] = {
    "Meskerem", "Tikimt", "Hidar", "Tahsas", "Tir", "Yekatit",
    "Megabit", "Miazia", "Genbot", "Sene", "Hamle", "Nehase"
};

struct RainfallData {
    double averageRainfall;
    double monthlyRainfall[NUM_MONTHS];
};

void displayRainfallTable(const RainfallData& data)
{
    cout << "Month\t\tRainfall\tDeviation from Average\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < NUM_MONTHS; ++i)
    {
        double rainfall = data.monthlyRainfall[i];
        double deviation = rainfall - data.averageRainfall;

        cout << left << setw(10) << MONTHS[i];
        cout << right << setw(10) << rainfall;
        cout << right << setw(10) << deviation << endl;
    }
}

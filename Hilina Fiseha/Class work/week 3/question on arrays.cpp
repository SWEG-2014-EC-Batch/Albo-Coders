#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 5;
double resistance[SIZE] = {16, 27, 39, 56, 81};
double current[SIZE];
double power[SIZE];

void get_current() {
    cout << "Enter five current values: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> current[i];
    }
}

void compute_power() {
    for (int i = 0; i < SIZE; i++) {
        power[i] = resistance[i] * pow(current[i], 2);
    }
}

void display_power() {
    cout << "Resistance\tCurrent\t\tPower" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << resistance[i] << "\t\t" << current[i] << "\t\t" << power[i] << endl;
    }
}

int main() {
    get_current();
    compute_power();
    display_power();
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

struct Person {
    string name;
    char gender;
    int age;
    double weight;
    double height;
};

double computeBMI(Person p) {
    double bmi = p.weight / pow(p.height / 100, 2);
    return bmi;
}

void displayBMI(Person p) {
    double bmi = computeBMI(p);
    cout << p.name << "'s BMI is " << bmi << endl;
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi < 25) {
        cout << "Normal weight" << endl;
    } else if (bmi < 30) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }
}

int main() {
    Person p;

    cout << "Enter person details:" << endl;
    cout << "Name: ";
    getline(cin, p.name);
    cout << "Gender (M/F): ";
    cin >> p.gender;
    cout << "Age: ";
    cin >> p.age;
    cout << "Weight (kg): ";
    cin >> p.weight;
    cout << "Height (cm): ";
    cin >> p.height;

    displayBMI(p);

    return 0;
}

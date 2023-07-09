#include <iostream>
#include <cmath>
using namespace std;

struct Person {
    string name;
    char gender;
    int age;
    float weight;
    float height;
};

int main() {
    Person person;


    cout << "Enter name: ";
    cin >> person.name;
    cout << "Enter gender (M/F): ";
    cin >> person.gender;
    cout << "Enter age: ";
    cin >> person.age;
    cout << "Enter weight (in kg): ";
    cin >> person.weight;
    cout << "Enter height (in m): ";
    cin >> person.height;


    float bmi = person.weight / pow(person.height, 2);


    cout << person.name << "'s BMI is " << bmi << endl;
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi < 25) {
        cout << "Normal weight" << endl;
    } else if (bmi < 30) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }

    return 0;
}

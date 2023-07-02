#include <iostream>
using namespace std;

struct person {
    std::string name;
    std::string gender;
    int age;
    double weight;
    double height;
};

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

void displayBMI(const person& p) {
    double bmi = calculateBMI(p.weight, p.height);

    cout << "Name: " << p.name << endl;
    cout << "Gender: " << p.gender <<endl;
    cout << "Age: " << p.age << endl;
    cout << "Weight: " << p.weight << " kg" << endl;
    cout << "Height: " << p.height << " m" << endl;
    cout << "BMI: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Message: Underweight" <<endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "Message: Normal weight" << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "Message: Overweight" << endl;
    } else {
        cout << "Message: Obesity" << endl;
    }
}

int main() {
    int numPeople;

    cout << "Enter the number of people: ";
    cin >> numPeople;

    // Create an array of person structures
    person people[numPeople];

    for (int i = 0; i < numPeople; ++i) {
        cout << "Person " << (i + 1) << " Details:" << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, people[i].name);

        cout << "Gender: ";
        getline(cin, people[i].gender);

        cout << "Age: ";
        cin >> people[i].age;

        cout << "Weight (in kg): ";
        cin >> people[i].weight;

        cout << "Height (in meters): ";
        cin >> people[i].height;
    }

        cout << endl;

    // Display BMI for each person
    for (int i = 0; i < numPeople; ++i) {
        cout << "Person " << (i + 1) << " BMI Details:" << endl;
        displayBMI(people[i]);
        cout << endl;
    }

    return 0;
}

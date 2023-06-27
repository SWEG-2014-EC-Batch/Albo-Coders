#include <iostream>

using namespace std;

struct Student {
    int id;
    string name;
    float testmark;
    float finalmark;
};

int main() {
    int n;
    float total = 0;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    // Input data for each student
    for (int i = 0; i < n; i++) {
        cout << "Enter student " << i+1 << " data:" << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Test Mark: ";
        cin >> students[i].testmark;
        cout << "Final Mark: ";
        cin >> students[i].finalmark;
        total += students[i].testmark + students[i].finalmark;
    }

    // Print records for each student
    cout << "Student Records:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Test Mark: " << students[i].testmark << endl;
        cout << "Final Mark: " << students[i].finalmark << endl;
    }

    // Compute and print total marks
    cout << "Total Marks: " << total << endl;

    return 0;
}

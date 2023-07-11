#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    double testMark;
    double finalMark;
};

void inputStudent(Student& s) {
    cout << "Enter student ID: ";
    cin >> s.id;
    cout << "Enter student name: ";
    cin >> s.name;
    cout << "Enter student test mark: ";
    cin >> s.testMark;
    cout << "Enter student final mark: ";
    cin >> s.finalMark;
}

void printStudent(Student s) {
    cout << "Student ID: " << s.id << endl;
    cout << "Student name: " << s.name << endl;
    cout << "Student test mark: " << s.testMark << endl;
    cout << "Student final mark: " << s.finalMark << endl;
}

int main() {
    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];
    double totalMark = 0;

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Enter data for student " << (i + 1) << ":" << endl;
        inputStudent(students[i]);
        totalMark += students[i].testMark + students[i].finalMark;
        cout << endl;
    }

    cout << "Total mark for all students: " << totalMark << endl;

    cout << "Student records:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << (i + 1) << ":" << endl;
        printStudent(students[i]);
        cout << endl;
    }

    return 0;
}

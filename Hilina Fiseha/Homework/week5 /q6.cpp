#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
    string name;
    double exam1;
    double exam2;
    double homework;
    double finalExam;
    double finalGrade;
    char letterGrade;
};

char calculateLetterGrade(double finalGrade) {
    if (finalGrade >= 90.0) {
        return 'A';
    } else if (finalGrade >= 80.0) {
        return 'B';
    } else if (finalGrade >= 70.0) {
        return 'C';
    } else if (finalGrade >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

void writeStudentDataToFile(const string& fileName, const Student* students, int count) {
    ofstream outputFile(fileName);
    if (!outputFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outputFile << "Name: " << students[i].name << endl;
        outputFile << "Exam 1: " << students[i].exam1 << endl;
        outputFile << "Exam 2: " << students[i].exam2 << endl;
        outputFile << "Homework: " << students[i].homework << endl;
        outputFile << "Final Exam: " << students[i].finalExam << endl;
        outputFile << "Final Grade: " << students[i].finalGrade << endl;
        outputFile << "Letter Grade: " << students[i].letterGrade << endl;
        outputFile << endl;
    }

    outputFile.close();
}

int main() {
    const int maxStudents = 20;
    Student students[maxStudents];
    int count;

    cout << "Enter the number of students (up to 20): ";
    cin >> count;

    if (count <= 0 || count > maxStudents) {
        cout << "Invalid number of students!" << endl;
        return 1;
    }

    // Enter student information
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << endl;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Exam 1: ";
        cin >> students[i].exam1;

        cout << "Exam 2: ";
        cin >> students[i].exam2;

        cout << "Homework: ";
        cin >> students[i].homework;

        cout << "Final Exam: ";
        cin >> students[i].finalExam;

        // Calculate final grade and letter grade
        students[i].finalGrade = 0.20 * students[i].exam1 + 0.20 * students[i].exam2 +
                                 0.35 * students[i].homework + 0.25 * students[i].finalExam;
        students[i].letterGrade = calculateLetterGrade(students[i].finalGrade);

        cout << endl;
    }

    // Display student information and write to file
    writeStudentDataToFile("student_records.txt", students, count);

    // Display student information on the console
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Exam 1: " << students[i].exam1 << endl;
        cout << "Exam 2: " << students[i].exam2 << endl;
        cout << "Homework: " << students[i].homework << endl;
        cout << "Final Exam: " << students[i].finalExam << endl;
        cout << "Final Grade: " << students[i].finalGrade << endl;
        cout << "Letter Grade: " << students[i].letterGrade << endl;
        cout << endl;
    }

    return 0;
}

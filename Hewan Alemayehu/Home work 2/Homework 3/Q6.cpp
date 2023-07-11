#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    double exam1;
    double exam2;
    double homework;
    double final_exam;
    double final_grade;
    char letter_grade;
};

char get_letter_grade(double final_grade) {
    if (final_grade >= 90.0) {
        return 'A';
    } else if (final_grade >= 80.0) {
        return 'B';
    } else if (final_grade >= 70.0) {
        return 'C';
    } else if (final_grade >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    const int MAX_STUDENTS = 20;
    Student students[MAX_STUDENTS];

    int num_students;
   cout << "Enter number of students (up to " << MAX_STUDENTS << "): ";
   cin >> num_students;

    for (int i = 0; i < num_students; i++) {
        cout << "Enter information for student " << (i + 1) << ":" << endl;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Exam 1: ";
        cin >> students[i].exam1;

        cout << "Exam 2: ";
        cin >> students[i].exam2;

        cout << "Homework: ";
        cin >> students[i].homework;

        cout << "Final exam: ";
        cin >> students[i].final_exam;

        students[i].final_grade = 0.20 * students[i].exam1 + 0.20 * students[i].exam2 + 0.35 * students[i].homework + 0.25 * students[i].final_exam;
        students[i].letter_grade = get_letter_grade(students[i].final_grade);

        cout << endl;
    }

    ofstream output_file("grades.txt");
    if (!output_file.is_open()) {
        cerr << "Failed to open output file\n";
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        output_file << "Name: " << students[i].name << endl;
        output_file << "Exam 1: " << students[i].exam1 << endl;
        output_file << "Exam 2: " << students[i].exam2 << endl;
        output_file << "Homework: " << students[i].homework << endl;
        output_file << "Final exam: " << students[i].final_exam << endl;
        output_file << "Final grade: " << students[i].final_grade << endl;
        output_file << "Letter grade: " << students[i].letter_grade << endl <<endl;
    }

    output_file.close();

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

struct Student {
    std::string name;
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

void writeStudentDataToFile(const std::string& fileName, const Student* students, int count) {
    std::ofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outputFile << "Name: " << students[i].name << std::endl;
        outputFile << "Exam 1: " << students[i].exam1 << std::endl;
        outputFile << "Exam 2: " << students[i].exam2 << std::endl;
        outputFile << "Homework: " << students[i].homework << std::endl;
        outputFile << "Final Exam: " << students[i].finalExam << std::endl;
        outputFile << "Final Grade: " << students[i].finalGrade << std::endl;
        outputFile << "Letter Grade: " << students[i].letterGrade << std::endl;
        outputFile << std::endl;
    }

    outputFile.close();
}

int main() {
    const int maxStudents = 20;
    Student students[maxStudents];
    int count;

    std::cout << "Enter the number of students (up to 20): ";
    std::cin >> count;

    if (count <= 0 || count > maxStudents) {
        std::cout << "Invalid number of students!" << std::endl;
        return 1;
    }

    // Enter student information
    for (int i = 0; i < count; i++) {
        std::cout << "Student " << i + 1 << std::endl;

        std::cout << "Name: ";
        std::cin >> students[i].name;

        std::cout << "Exam 1: ";
        std::cin >> students[i].exam1;

        std::cout << "Exam 2: ";
        std::cin >> students[i].exam2;

        std::cout << "Homework: ";
        std::cin >> students[i].homework;

        std::cout << "Final Exam: ";
        std::cin >> students[i].finalExam;

        // Calculate final grade and letter grade
        students[i].finalGrade = 0.20 * students[i].exam1 + 0.20 * students[i].exam2 +
                                 0.35 * students[i].homework + 0.25 * students[i].finalExam;
        students[i].letterGrade = calculateLetterGrade(students[i].finalGrade);

        std::cout << std::endl;
    }

    // Display student information and write to file
    writeStudentDataToFile("student_records.txt", students, count);

    // Display student information on the console
    for (int i = 0; i < count; i++) {
        std::cout << "Student " << i + 1 << std::endl;
        std::cout << "Name: " << students[i].name << std::endl;
        std::cout << "Exam 1: " << students[i].exam1 << std::endl;
        std::cout << "Exam 2: " << students[i].exam2 << std::endl;
        std::cout << "Homework: " << students[i].homework << std::endl;
        std::cout << "Final Exam: " << students[i].finalExam << std::endl;
        std::cout << "Final Grade: " << students[i].finalGrade << std::endl;
        std::cout << "Letter Grade: " << students[i].letterGrade << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

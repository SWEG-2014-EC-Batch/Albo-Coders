#include <iostream>
#include <cmath>
// answer to question 5
double calculateResult(double num1, double num2) {
    double cube = pow(num1, 3);              // Cube of num1
    double squareRoot = sqrt(num2);          // Square root of num2
    double answer = cube + squareRoot;       // Sum of cube and square root
    return answer;
}

int main() {
    double num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    double result = calculateResult(num1, num2);
    std::cout << "The result is: " << result << std::endl;

    return 0;
}

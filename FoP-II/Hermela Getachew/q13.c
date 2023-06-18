#include <iostream>
using namespace std;
double max(double a, double b) {
    return (a > b) ? a : b;
}

double max(double a, double b, double c) {
    return max(max(a, b), c);
}

int main() {
    double num1 = 10.5, num2 = 8.7, num3 = 12.9;
    double largest;

    largest = max(num1, num2);
    cout << "The largest value between " << num1 << " and " << num2 << " is: " << largest << endl;

    largest = max(num1, num2, num3);
    cout << "The largest value among " << num1 << ", " << num2 << ", and " << num3 << " is: " << largest << endl;

    return 0;
}

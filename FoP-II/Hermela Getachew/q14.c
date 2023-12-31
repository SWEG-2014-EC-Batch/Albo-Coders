#include <iostream>
using namespace std;
int fibonacci(int n = 10) {
    int first = 0, second = 1;

    if (n <= 0) {
        cout << "Invalid input! Please enter a positive integer." << endl;
        return -1;
    }

    cout << "Fibonacci series of " << n << " numbers: ";

    if (n >= 1) {
        cout << first << " ";
    }

    if (n >= 2) {
        cout << second << " ";
    }

    for (int i = 3; i <= n; ++i) {
        int current = first + second;
        cout << current << " ";
        first = second;
        second = current;
    }

    cout << endl;

    return second;
}

int main() {
    int num;

    cout << "Enter a number to calculate Fibonacci series (default is 10): ";
    cin >> num;

    int result = fibonacci(num);
    cout << "The last number in the Fibonacci series is: " << result << endl;

    result = fibonacci();  // Calling without a parameter
    cout << "The last number in the default Fibonacci series is: " << result << endl;

    return 0;
}

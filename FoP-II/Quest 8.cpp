// answer to question 8
#include <iostream>

bool isPrime(int number) {
    if (number < 2 || number > 1000)
        return false;

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main() {
    int testNumbers[] = {17, 20, 73, 100, 113, 500, 997};

    for (int i = 0; i < sizeof(testNumbers) / sizeof(testNumbers[0]); ++i) {
        int number = testNumbers[i];
        std::cout << "Is " << number << " prime? " << (isPrime(number) ? "true" : "false") << std::endl;
    }

    return 0;
}

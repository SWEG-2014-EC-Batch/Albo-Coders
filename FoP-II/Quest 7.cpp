// answer to question 7
#include <iostream>
#include <cstdarg>

int product(int count, ...) {
    va_list args;
    va_start(args, count);

    int result = 1;
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        result *= num;
    }

    va_end(args);

    return result;
}

int main() {
    // Test with different number of arguments
    std::cout << "Product of 3, 4, 5: " << product(3, 3, 4, 5) << std::endl;
    std::cout << "Product of 2, 6, 8, 10: " << product(4, 2, 6, 8, 10) << std::endl;
    std::cout << "Product of 1, 2, 3, 4, 5, 6: " << product(6, 1, 2, 3, 4, 5, 6) << std::endl;

    return 0;
}

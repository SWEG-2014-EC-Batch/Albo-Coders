#include <iostream>

char* toUppercase(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char* uppercase_str = new char[length + 1];
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            uppercase_str[i] = str[i] - 'a' + 'A';
        } else {
            uppercase_str[i] = str[i];
        }
    }
    uppercase_str[length] = '\0';
    return uppercase_str;
}

int main() {

    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];


    std::cout << "Enter a string: ";
    std::cin.getline(str, MAX_LENGTH);


    char* uppercase_str = toUppercase(str);


    std::cout << "Uppercase string: " << uppercase_str << std::endl;


    delete[] uppercase_str;

    return 0;
}

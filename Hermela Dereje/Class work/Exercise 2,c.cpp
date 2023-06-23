#include <iostream>

int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {

    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    std::cout << "Enter the first string: ";
    std::cin.getline(str1, MAX_LENGTH);
    std::cout << "Enter the second string: ";
    std::cin.getline(str2, MAX_LENGTH);


    int result = compareStrings(str1, str2);


    if (result == 0) {
        std::cout << "The two strings are equal" << std::endl;
    } else if (result == 1) {
        std::cout << "The first string is greater" << std::endl;
    } else {
        std::cout << "The second string is greater" << std::endl;
    }

    return 0;
}

#include <iostream>

void countVowelsAndConsonants(const char* str, int& length, int& num_vowels, int& num_consonants) {
    length = 0;
    num_vowels = 0;
    num_consonants = 0;


    while (str[length] != '\0') {
        length++;
    }


    for (int i = 0; i < length; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z'  ch >= 'A' && ch <= 'Z') {
            if (ch == 'a'  ch == 'e'  ch == 'i'  ch == 'o'  ch == 'u' 
                ch == 'A'  ch == 'E'  ch == 'I'  ch == 'O'  ch == 'U') {
                num_vowels++;
            } else {
                num_consonants++;
            }
        }
    }
}

int main() {

    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];


    std::cout << "Enter a string: ";
    std::cin.getline(str, MAX_LENGTH);


    int length, num_vowels, num_consonants;
    countVowelsAndConsonants(str, length, num_vowels, num_consonants);


    std::cout << "Length of string: " << length << std::endl;
    std::cout << "Number of vowels: " << num_vowels << std::endl;
    std::cout << "Number of consonants: " << num_consonants << std::endl;

    return 0;
}

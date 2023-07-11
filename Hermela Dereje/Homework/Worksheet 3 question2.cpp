#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("Sheet5Ex5.cpp");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int charCounts[26] = {0};
    char ch;

    // Count occurrences of lowercase characters
    while (inputFile.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            charCounts[ch - 'a']++;
        }
    }

    inputFile.close();

    std::cout << "CHARACTER OCCURRENCES" << std::endl;
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << " " << charCounts[i] << std::endl;
    }

    return 0;
}

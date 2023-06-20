#include <iostream>
#include <string>

using namespace std;

void printVowels(const string& str) {
    cout << "Vowel letters: ";
    for (char c : str) {
        char lowercaseChar = tolower(c);
        if (lowercaseChar == 'a'  lowercaseChar == 'e'  lowercaseChar == 'i'  lowercaseChar == 'o'  lowercaseChar == 'u') {
            cout << c << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    printVowels(input);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
void printVowels(string str) {
    cout << "Vowel Letters: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i'||  ch == 'o'||  ch == 'u'||
            ch == 'A'||  ch == 'E'||  ch == 'I' || ch == 'O' || ch == 'U') {
            cout << ch << " ";
        }
    }
    cout << endl;
}

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);
    printVowels(inputStr);
    return 0;
}

#include <iostream>
using namespace std; 

void reverseString(const char* str, char* reversed_str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length; i++) {
        reversed_str[i] = str[length - i - 1];
    }
    reversed_str[length] = '\0';
}

int main() {

    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];


    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);

    char reversed_str[MAX_LENGTH];

    reverseString(str, reversed_str);


    cout << "Reversed string: " << reversed_str << endl;

    return 0;
}

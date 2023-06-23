#include <iostream>
using namespace std;
char* toLowercase(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char* lowercase_str = new char[length + 1];
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lowercase_str[i] = str[i] - 'A' + 'a';
        } else {
            lowercase_str[i] = str[i];
        }
    }
    lowercase_str[length] = '\0';
    return lowercase_str;
}

int main() {

    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];


    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);


    char* lowercase_str = toLowercase(str);


 cout << "Lowercase string: " << lowercase_str << endl;


    delete[] lowercase_str;

    return 0;
}

#include <iostream>
using namespace std;

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

    cout << "Enter the first string: ";
    cin.getline(str1, MAX_LENGTH);
    cout << "Enter the second string: ";
    cin.getline(str2, MAX_LENGTH);


    int result = compareStrings(str1, str2);


    if (result == 0) {
        cout << "The two strings are equal" <<endl;
    } else if (result == 1) {
        cout << "The first string is greater"<<endl;
    } else {
     cout<< "The second string is greater"<<endl;
    }

    return 0;
}

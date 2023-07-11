#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("Sheet5Ex5.cpp");
    if (!inputFile) {
       cerr << "Error opening file!" <<endl;
        return 1;
    }

    int charCounts[26] = {0};
    char ch;

    while (inputFile.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            charCounts[ch - 'a']++;
        }
    }

    inputFile.close();

   cout << "CHARACTER OCCURRENCES" << endl;
    for (int i = 0; i < 26; i++) {
        cout << static_cast<char>('a' + i) << " " << charCounts[i] << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("data_file.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        int sum = 0;
        int count = num;
        for (int i = 0; i < num; i++) {
            inputFile >> num;
            sum += num;
        }

        double average = static_cast<double>(sum) / count;
        cout << "Group average: " << average << endl;
    }

    inputFile.close();
    return 0;
}

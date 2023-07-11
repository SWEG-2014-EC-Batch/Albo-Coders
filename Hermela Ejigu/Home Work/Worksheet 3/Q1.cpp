#include <iostream>
#include <fstream>
using namespace std;

void readIntegerFile(const char* fileName, int* array, int* count) {
    ifstream inputFile(fileName);
    if (!inputFile) {
       cerr << "Error opening file: " << fileName << endl;
        return;
    }

    int num;
    *count = 0;
    while (inputFile >> num) {
        array[*count] = num;
        (*count)++;
    }

    inputFile.close();
}

int main() {
    const char* fileName = "integer_records.txt";  // Replace with the actual file name
    int array[100];  // Assuming the array has enough space
    int count;

    readIntegerFile(fileName, array, &count);

   cout << "Number of entries: " << count << endl;
    cout << "Array contents: ";
    for (int i = 0; i < count; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
   

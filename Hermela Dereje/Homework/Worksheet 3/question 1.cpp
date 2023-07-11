#include <iostream>
#include <fstream>

void readIntegerFile(const char* fileName, int* array, int* count) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
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

    std::cout << "Number of entries: " << count << std::endl;
    std::cout << "Array contents: ";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

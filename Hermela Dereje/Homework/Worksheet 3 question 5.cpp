#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("data_file.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
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
        std::cout << "Group average: " << average << std::endl;
    }

    inputFile.close();
    return 0;
}

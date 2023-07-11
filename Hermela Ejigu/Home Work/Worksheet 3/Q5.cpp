#include <iostream>
#include <fstream>
using namespace std;

int main() {

   ifstream input_file("data.txt");
    if (!input_file.is_open()) {
        cerr << "Failed to open input file\n";
       return 1;
    }


    int num_groups, num, count;
    double sum, average;
    while (input_file >> num_groups) {
        sum = 0.0;
        count = 0;
        for (int i = 0; i < num_groups; i++) {
            input_file >> num;
            sum += num;
            count++;
        }
        average = sum / count;
        cout << "Average of group of " << num_groups << " numbers: " << average <<endl;
    }


    input_file.close();

    return 0;
}

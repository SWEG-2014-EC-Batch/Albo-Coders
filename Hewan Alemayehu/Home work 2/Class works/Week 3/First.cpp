#include <iostream>
using namespace std;

void printFirstAndLastElement(double arr[], double size) {
    cout << "First Element: " << arr[0] << endl;
    cout << "Last Element: " << arr[int(size) - 1] << endl;
    cout << "Sum: " << arr[0] + arr[int(size) - 1] << endl;
}

int main() {
    double size;
    cout << "Enter the size of the array: ";
    cin >> size;

    double * arr = new double[int(size)];

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < int(size); i++) {
        cin >> arr[i];
    }

    printFirstAndLastElement(arr, size);

    delete[] arr;

    return 0;
}

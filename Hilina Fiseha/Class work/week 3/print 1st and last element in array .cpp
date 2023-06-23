#include <iostream>
using namespace std;
void printFirstAndLastElement(double arr[], int size) {
    cout << "First Element: " << arr[0]<<endl;
    cout << "Last Element: " << arr[size - 1] << endl;
    cout << "Sum: " << arr[0] + arr[size - 1] << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    double* arr = new double[size];

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    printFirstAndLastElement(arr, size);

    delete[] arr;

    return 0;
}

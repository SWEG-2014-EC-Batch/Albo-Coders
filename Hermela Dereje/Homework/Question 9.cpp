
#include <iostream>
using namespace std;

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortValues(int& num1, int& num2, int& num3) {
    cout << "Before sorting: " << num1 << " " << num2 << " " << num3 << endl;
    if (num1 < num2) {
        swapValues(num1, num2);
    }
    if (num1 < num3) {
        swapValues(num1, num3);
    }
    if (num2 < num3) {
        swapValues(num2, num3);
    }
    cout << "After sorting: " << num1 << " " << num2 << " " << num3 << endl;
}

int main() {
    int a = 10, b = 5, c = 20;
    sortValues(a, b, c);
    return 0;
}

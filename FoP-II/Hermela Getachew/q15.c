#include <iostream>
#include <cassert>
using namespace std;
void scale(double scaleFactor, double& value1, double& value2) {
    assert(scaleFactor != 0.0);

    cout << "Before scaling: value1 = " << value1 << ", value2 = " << value2 << endl;

    value1 *= scaleFactor;
    value2 *= scaleFactor;

    cout << "After scaling: value1 = " << value1 << ", value2 = " << value2 << endl;
}

int main() {
    double scaleFactor;
    double value1, value2;

    cout << "Enter a scaling factor: ";
    cin >> scaleFactor;

    cout << "Enter value 1: ";
    cin >> value1;

    cout << "Enter value 2: ";
    cin >> value2;

    scale(scaleFactor, value1, value2);

    return 0;
}

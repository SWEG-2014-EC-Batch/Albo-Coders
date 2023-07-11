#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};

// Function to add two complex numbers
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

// Function to divide two complex numbers
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = (b.real * b.real) + (b.imag * b.imag);
    result.real = ((a.real * b.real) + (a.imag * b.imag)) / denominator;
    result.imag = ((a.imag * b.real) - (a.real * b.imag)) / denominator;
    return result;
}

int main() {
    Complex a = {2, 3};
    Complex b = {4, 5};
    Complex sum = add(a, b);
    Complex diff = subtract(a, b);
    Complex prod = multiply(a, b);
    Complex quot = divide(a, b);

    cout << "a = " << a.real << " + " << a.imag << "i" << endl;
    cout << "b = " << b.real << " + " << b.imag << "i" << endl;
    cout << "a + b = " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "a - b = " << diff.real << " + " << diff.imag << "i" << endl;
    cout << "a * b = " << prod.real << " + " << prod.imag << "i" << endl;
    cout << "a / b = " << quot.real << " + " << quot.imag << "i" << endl;

    return 0;
}

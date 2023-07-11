#include <iostream>

using namespace std;

struct Complex {
    double real;
    double imaginary;
};


Complex addComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}


Complex subtractComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}


Complex multiplyComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}


Complex divideComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    double denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;
    result.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denominator;
    result.imaginary = (c1.imaginary * c2.real - c1.real * c2.imaginary) / denominator;
    return result;
}

int main() {
    Complex c1, c2;

    cout << "Enter real and imaginary parts of first complex number:" << endl;
    cin >> c1.real >> c1.imaginary;

    cout << "Enter real and imaginary parts of second complex number:" << endl;
    cin >> c2.real >> c2.imaginary;

    Complex sum = addComplex(c1, c2);
    Complex difference = subtractComplex(c1, c2);
    Complex product = multiplyComplex(c1, c2);
    Complex quotient = divideComplex(c1, c2);

    cout << "Sum: " << sum.real << " + " << sum.imaginary << "i" << endl;
    cout << "Difference: " << difference.real << " + " << difference.imaginary << "i" << endl;
    cout << "Product: " << product.real << " + " << product.imaginary << "i" << endl;
    cout << "Quotient: " << quotient.real << " + " << quotient.imaginary << "i" << endl;

    return 0;
}

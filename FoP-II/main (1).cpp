#include <iostream>

using namespace std;

double getProduct(int num1 , double num2){ // function declaration for the getProduct function
    double product = num1 * num2;
    return product;
}
int main() {
    int firstNum ;
    double secondNum;
    cout << "enter an integer:";
    cin >> firstNum;
    cout << "enter a double:";
    cin >> secondNum;
    double product = getProduct(firstNum , secondNum); // this line calls the 'getProduct' function with the values of 'firstNum' and 'secondNum' as arguments , and assigns the result to the 'product' variable'.
    cout << "the product of " << firstNum << " and " << secondNum << " is " << product << endl;
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

double hypotenuse(double side1 , double side2){
double hypotenuse = sqrt(pow(side1 , 2) + pow (side2,2));
return hypotenuse;
}
int main() {
 double side1 , side2 , hyp;
 // calculate hypotenuse for triangle with sides 3.0 and 4.0
 side1 = 3.0;
 side2 = 4.0;
 hyp = hypotenuse(side1 , side2);
 cout << "For triangle with sides " << side1 << " and " << side2 << ", the hypotenuse is " << hyp << endl;
 // calculate hypotenuse for triangle with sides 5.0 and 12.0
  side1 = 5.0;
 side2 = 12.0;
 hyp = hypotenuse(side1 , side2);
 cout << "For triangle with sides " << side1 << " and " << side2 << ", the hypotenuse is " << hyp << endl;
 // calculate hypotenuse for triangle with sides 8.0 and 15.0
 side1 = 8.0;
 side2 = 15.0;
 hyp = hypotenuse(side1 , side2);
 cout << "For triangle with sides " << side1 << " and " << side2 << ", the hypotenuse is " << hyp << endl;
 return 0;
}

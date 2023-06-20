#include<iostream>
using namespace std;
double max(double x, double y);
double max(double x, double y,double z);
int main(){
    double x,y,z;
    int num;
cout << "enter the amount of number you want to compare";
cin>> num;
if (num==2) {
    cout <<"enter two numbers";
    cin>> x >> y;
    cout << max(x,y);
}else {
    cout <<"enter numbers up to three numbers";
    cin>> x>> y>> z;
    cout<< max(x,y,z);
}}
double max(double x, double y){
    if(x>y){
        return x;
    }else {
        return y;
    }
}
double max(double x, double y,double z){
    if (x>y){
        if (y>z){
         cout << x;
        }
        }else {
            if (y>z){
                return y;
            }else {
                return z;
            }
        }
    }

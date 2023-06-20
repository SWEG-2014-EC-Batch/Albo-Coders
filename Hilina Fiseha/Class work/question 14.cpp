#include<iostream>
using namespace std;
int fibonacci(int num=10);
int a=0, b=1,c;

int main(){
    int amount;
    cout<< "enter a number";
    cin >>amount;
    if(amount==0){
        fibonacci();
    }else {
        fibonacci(amount);
    }
}
int fibonacci(int amount){
    for(int i=0;i<amount;i++){
    c=a+b;
    a=b;
    b=c ;
   cout <<c<<",";
    }
    
}

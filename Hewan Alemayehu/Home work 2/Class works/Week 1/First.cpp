#include <iostream>
#include<ctype.h>
#include<string.h>
using namespace std;

//void name ();
void a();
void b();
int main(){
    a();
    b();
   // name();
    
}
void a(){
    cout << "hi";
    b();
}
void b(){
    cout << " Hew"; 
    a();
}

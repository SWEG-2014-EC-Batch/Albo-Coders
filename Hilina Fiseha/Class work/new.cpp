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
    cout << "hey";
    b();
}
void b(){
    cout << " bye"; 
    a();
}

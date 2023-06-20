#include <iostream>

using namespace std;

int leapyear(int year);
  int main()
  {
     int year;
     cout<<"enter the year"<<endl;
     cin>>year;
     int leap=leapyear(year);
     if(leap){
       cout<<"it is a leap year"<<endl;

     }else

     cout<<"it is not a leap year"<<endl;
  }

int leapyear(int year)
{
  if((year%4==0&&year%100!=0)||year%400==0)
  {
      return 1;
  }else
  {
      return 0;
  }

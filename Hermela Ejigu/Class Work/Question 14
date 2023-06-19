#include <iostream>

using namespace std;

int fibonnaci(int num=10)
{
    int s1=1,s2=1,next;
    cout<<"Fibonacci series:"<<s1<<","<<s2<<",";
    next=s1+s2;
    while(next<=num)
        {
           cout<<next<<",";
           s1=s2;
           s2=next;
           next=s1+s2;
        }

}
int main()
{
    int num;
    int choice;
    cout<<"WOULD YOU LIKE TO ENTER A NUMBER:[1=yes,0=no]";
    cin>>choice;
    if(choice==1)
    {
            cout<<"ENTER THE MAXIMUM NUMBER:";
            cin>>num;
            fibonnaci(num);
    }

    else
    {
        fibonnaci();
    }


    return 0;
}

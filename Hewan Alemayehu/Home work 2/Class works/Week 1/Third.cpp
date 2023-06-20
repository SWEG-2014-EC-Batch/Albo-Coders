#include <iostream>
using namespace std;

bool Year(int x);

int main()
{
    int x;
    cout << Year(x);
    if (Year(x) == 1)
    {
        cout << "It's a leap year";
    }
    return 0;
}

bool Year(int x)
{
    cout << "Enter a year for checking if it is a leap year" << endl;
    cin >> x;
    if (x % 4 == 0 ^ (x % 100 != 0 && x % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

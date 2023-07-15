#include <iostream>

using namespace std;
// pattern print using function
void printPattern(char letter, char limit, int space)
{
    for (char i = letter; i >= limit; i--)
    {
        for (char j = limit; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 0; k < space; k++)
        {
            cout << " ";
        }
        for (char j = i; j >= limit; j--)
        {
            if (j < letter)
                cout << j;
        }
        space += 2;
        cout << endl;
    }
    
cout << " ";
        }
        for (char j = i; j >= limit; j--)
        {
            if (j < letter)
                cout << j;
        }
        cout << endl;
        space -= 2;
    }
}
    space -= 4;

    for (char i = limit + 1; i <= letter; i++)
    {
        for (char j = limit; j <= i; j++)
        {
            cout << j;
        }
        for (int k = space; k > 0; k--)
        {

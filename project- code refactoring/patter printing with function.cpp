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


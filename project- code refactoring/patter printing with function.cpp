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

int main()
{
    char letter, limit;
    int space = -1;

    cout << "Enter a letter or a digit: " << endl;
    cin >> letter;

    if (letter >= '1' && letter <= '9')
    {
        limit = '0';
    }
else if (letter >= 'a' && letter <= 'z')
    {
        limit = 'a';
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        limit = 'A';
    }
  else
    {
        cout << "Invalid input." << endl;
        return 0;
    }

    printPattern(letter, limit, space);

    return 0;
}

// 3. Переписана програма без cin.putback() та cin.ignore().

#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch))
    {
        if (ch == '!')
            cout << '$';
        else if (ch == '#')
            continue;
        else
            cout << ch;
    }

    return 0;
}

// enter a phrase: Now!is#the!time#for!fun#!
// Now$isthe$timefor$fun$

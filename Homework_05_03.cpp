/*
    3. Оголошено, що функція myFunc не повертатиме нічого (void), але в її тілі
       наявний return, отже необхідно замінити void на unsigned short int.
       Також в функції main функція myFunc викликається з недопустимим
       аргументом int. Припускаю, що там має бути вказана змінна x. Якщо так,
       то також варто ініціалізувати x перед викликом myFunc, адже зараз він
       дорівнює 0, і тому myFunc завжди повертатиме 0.
*/

#include <iostream>
using namespace std;

void myFunc(unsigned short int x);
int main()
{
    unsigned short int x, y;
    y = myFunc(int);
    cout << "x: " << x << "y: " << y << "\n";
}
void myFunc(unsigned short int x)
{
    return (4 * x);
}

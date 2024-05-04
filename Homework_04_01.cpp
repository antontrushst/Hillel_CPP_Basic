/*
    Цей код запитує в користувача два числа,
    та прирівнює одне з них до меншого, використовуючи
    if оепратор з одним додатковим оператором else.
*/

#include <iostream>

void makeBiggerSmaller(int& a, int& b)
{
    if (a > b)
    {
        a = b;
    }
    else
    {
        b = a;
    }
}

int main()
{
    int a = 0;
    int b = 0;
    std::cout << "Enter first number:\n>>> ";
    std::cin >> a;
    std::cout << "Enter second number:\n>>> ";
    std::cin >> b;
    makeBiggerSmaller(a, b);
    std::cout << "\na = " << a << "\nb = " << b << std::endl;
}
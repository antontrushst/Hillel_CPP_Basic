// 1. Програма запитує в користувача число та ступінь, і виводить в термінал
//    результат возведення заданого числа в задану ступінь.

#include <iostream>

int toThePowerOf(short int num, short int pow);

int main()
{
    short int number = 0;
    short int power  = 0;

    std::cout << "Enter a number: \n>>> ";
    std::cin >> number;
    std::cout << "Enter the power of: \n>>> ";
    std::cin >> power;

    std::cout << std::endl << number << " to the power of " << power << " is: "
    << toThePowerOf(number, power);

    return 0;
}

int toThePowerOf(short int num, short int pow)
{
    if (pow == 1) return num;

    return num * toThePowerOf(num, pow - 1);
}

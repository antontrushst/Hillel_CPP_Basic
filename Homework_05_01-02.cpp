/*
    1. | 2. Цей код запитує в користувача довжину та ширину прямокутника
            і виводить в якості результату його периметр.
*/

#include <iostream>

unsigned long Perimeter(unsigned short int length, unsigned short int width);

int main()
{
    unsigned short int input_length = 0;
    unsigned short int input_width  = 0;

    std::cout << "Enter length:\n>>> ";
    std::cin >> input_length;
    std::cout << "\nEnter width:\n>>> ";
    std::cin >> input_width;
    std::cout << "\nPerimeter is: " << Perimeter(input_length, input_width);

    return 0;
}

unsigned long Perimeter(unsigned short int length, unsigned short int width)
{
    return (length *= 2) + (width *= 2);
}

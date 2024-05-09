/*
    5. | 6. Программа запитує в користувача два числа, і у разі, якщо друге
            число не дорівнює 0 (нулю), виводить результат ділення першого
            на друге.
*/

#include <iostream>

float Divide(unsigned short int a, unsigned short int b);

int main()
{
    unsigned short int num1 = 0;
    unsigned short int num2 = 0;
    float divisionResult = 0;

    std::cout << "Enter first number:\n>>> ";
    std::cin >> num1;
    std::cout << "Enter second number:\n>>> ";
    std::cin >> num2;
    
    divisionResult = Divide(num1, num2);
    
    if (divisionResult == -1)
    {
        std::cout << "\nSecond number cannot be 0!!!";
        return 0;
    }
    std::cout << "\nThe result of dividing these two numbers is: "
              << divisionResult;

    return 0;
}

float Divide(unsigned short int a, unsigned short int b)
{
    return (b != 0) ? (float)a / (float)b : -1;
}

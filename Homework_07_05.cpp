// 5. Програма виконує цикл do/while, який змінює змінну лічильника counter від
//    100 до 200 з кроком 2 (та виводить в термінал процес для наглядності).

#include <iostream>

int main()
{
    int counter = 100;
    do
    {
        std::cout << counter << "\n";
        counter += 2;
    }
    while (counter < 200);
    std::cout << counter;

    return 0;
}

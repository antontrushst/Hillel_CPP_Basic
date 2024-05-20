// 3. Програма виконує цикл, яким змінює змінну лічильника counter від 100 до
//    200 з кроком 2 (та виводить свої дії в термінал для наглядності).

#include <iostream>

int main()
{
    int counter = 100;
    for (; counter < 200; counter += 2)
    {
        std::cout << counter << "\n";
    }
    std::cout << counter;

    return 0;
}
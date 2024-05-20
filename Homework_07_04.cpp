// 4. Програма виконує цикл while, який змінює змінну лічильника counter зі 100
//    до 200 з кроком 2 (та виводить процес в термінал для наглядності).

#include <iostream>

int main()
{
    int counter = 100;
    while (counter < 200)
    {
        std::cout << counter << "\n";
        counter += 2;
    }
    std::cout << counter;

    return 0;
}

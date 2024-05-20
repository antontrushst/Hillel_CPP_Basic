// 1. Значення змінної х буде дорівнювати 100.

// 2. Програма заповнює та виводить в термінал матрицю нулів 10х10.

#include <iostream>

int main()
{
    for (int rows = 10; rows > 0; rows--)
    {
        for (int columns = 10; columns > 0; columns--)
        {
            std::cout << "0 ";
        }
        std::cout << "\n";
    }

    return 0;
}
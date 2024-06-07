// 1. В рядку 7 оголошується двовимірний масив для поля гри хрестики-нулики.
// 2. В функції main() масив XO[] ініціалізується нулями, а потім виводиться
//    в термінал для наглядності.

#include <iostream>

char XO[3][3];

int main()
{
    for (int i = 0; i < (sizeof(XO) / sizeof(char)); i++)
        for (int j = 0; j < (sizeof(XO[0]) / sizeof(char)); j++)
            XO[i][j] = '0';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << XO[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}

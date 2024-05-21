// 4. Програма створює змінну myVar та вказівник до неї, завдяки якому
//    надає значення цій змінній (значення змінної myVar виводиться в термінал
//    для наглядності).

#include <iostream>

int main()
{
    int myVar;
    int *pMyVar = &myVar;
    *pMyVar = 75300;
    std::cout << myVar;

    return 0;
}

// 1. Програма оголошує змінну myVar і ініціалізує їй значення 78,
//    оголошує посилання rMyVar та ініціалізує його до змінної myVar,
//    а також оголошує вказівник pMyVar та ініціалізує його адресою myVar.
//    Далі програма змінює значення myVar за допомогою посилання та
//    вказівника (і виводить значення myVar в термінал для наглядності).

#include <iostream>

int main()
{
    int myVar = 78;
    int &rMyVar = myVar;
    int *pMyVar = &myVar;

    std::cout << "myVar initially: " << myVar << "\n";
    rMyVar += 3;
    std::cout << "myVar after reference + 3: " << myVar << "\n";
    *pMyVar += 7;
    std::cout << "myVar after pointer + 7: " << myVar;

    return 0;
}

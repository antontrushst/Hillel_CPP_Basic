// 1. int *pOne; - оголошення вказівника без ініціалізації (так краще не робити,
//    а одразу ініціалізувати вказівник як nullptr чи з адресою).
//    int vTwo; - оголошення змінної без ініціалізації.
//    int *pThree = $vTwo; - оголошення та ініціалізація вказівника, який
//    приймає як значення адресу змінної vTwo.

// 2-3. Програма створює зміну yourAge та вказівник до неї, за допомогою якого
//      змінює значення цієї змінної з 29 на 50.

#include <iostream>

int main()
{
    unsigned short yourAge = 29;
    std::cout << "your Age before pointer: " << yourAge << "\n";
    unsigned short *pYourAge = &yourAge;
    *pYourAge = 50;
    std::cout << "yourAge after pointer: " << yourAge;

    return 0;
}

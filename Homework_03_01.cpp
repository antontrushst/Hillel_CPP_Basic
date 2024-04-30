/*
Відповіді на питання ДЗ номер 3:
    1. Ваш вік - тип unsigned char, оскільки ані більше 255 років,
       ані в мінус жити не вийде.

    2. Площа вашого заднього двору - тип float, бо скоріше за все
       матимемо значення з плаваючою точкою де ціле число репрезентуватиме
       метри, а за крапкою сантиметри (залежить від одиниць вимірювання).

    3. Кількість зірок у галактиці - тип unsigned long long int,
       оскільки залежно від галактики зірок може бути ну дуже багато,
       а тому беремо найбільший тип цілого числа, який не може бути з мінусом.

    4. Середній рівень випадання опадів за січень - тип unsigned short int,
       бо це має бути позитивне ціле значення в міліметрах, яке навряд колись
       перевищить ліміт цього типу.
*/

#include <iostream>

unsigned char myAge = 29;
float myBackyard_S = 67.2f;
unsigned long long int starsNum_MilkyWay = 300000000000;
unsigned short int avrPrecipitation_January = 310;

const double pi = 3.14159;
float piF = pi;

int main()
{
    std::cout << "I'm " << 0 + myAge << " years old." << std::endl;
    std::cout << "My backyard square is: " << myBackyard_S << " m2." << std::endl;
    std::cout << "There are around " << starsNum_MilkyWay << " stars in Milky Way."<< std::endl;
    std::cout << "The avarage precipitation amount in January is " << avrPrecipitation_January
              << " mm." << std::endl << std::endl;
    std::cout << "Pi = " << pi << std::endl;
    std::cout << "Float Pi = " << piF << std::endl;

    return 0;
}

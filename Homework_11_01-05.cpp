/*  1. Перевантажені оператори преінкремент та постінкремент для класу
       SimpleCircle (рядки 28 - 34).
    2. Значення itsRadius змінений для зберігання в динамічній пам'яті,
       відповідних змін зазнали функції та конструктори класу (рядки 16 - 26).
    3. Створений конструктоп-копювальник (рядки 21 - 22).
    4. Перевантаження оператора присвоєння (рядки 35 - 43).
    5. Функція main() містить маніпуляції з об'єктами класу SimpleCircle згідно
       з завданням (створення різними конструкторами, преінкремент/постінкремент,
       надання значення одного об'єкта іншому перевантаженим оператором
       присвоєння). */

#include <iostream>

class SimpleCircle
{
    unsigned short *itsRadius;

public:
    SimpleCircle() : itsRadius(new unsigned short(5)) {}
    SimpleCircle(unsigned short r) : itsRadius(new unsigned short(r)) {}
    SimpleCircle(SimpleCircle &rCircle)
        : itsRadius(new unsigned short(*rCircle.itsRadius)) {}
    ~SimpleCircle() { delete itsRadius; }

    unsigned short GetRadius() const { return *this->itsRadius; }
    void SetRadius(unsigned short newRadius) { *this->itsRadius = newRadius; }

    SimpleCircle& operator ++ () { ++*itsRadius; return *this; }
    SimpleCircle operator ++ (int)
    {
        SimpleCircle temp = *this;
        ++*itsRadius;
        return temp;
    }
    SimpleCircle& operator = (const SimpleCircle&);
};

SimpleCircle& SimpleCircle::operator = (const SimpleCircle &rhs)
{
    if (this == &rhs) { return *this; }
    *itsRadius = rhs.GetRadius();
    return *this;
}

int main()
{
    SimpleCircle Circle_1;
    SimpleCircle Circle_2(9);

    std::cout << "\nCircle_1 radius is: " << Circle_1.GetRadius() << "\n";
    std::cout << "Circle_2 radius is: " << Circle_2.GetRadius() << "\n\n";
    std::cout << "Prefix incrementing Circle_1 and postfix incrementing Circle_2...\n";
    ++Circle_1;
    Circle_2++;
    std::cout << "Circle_1 radius is: " << Circle_1.GetRadius() << "\n";
    std::cout << "Circle_2 radius is: " << Circle_2.GetRadius() << "\n\n";
    std::cout << "Assigning Circle_1 to Circle_2...\n";
    Circle_1 = Circle_2;
    std::cout << "Circle_1 radius is: " << Circle_1.GetRadius() << "\n";
    std::cout << "Circle_2 radius is: " << Circle_2.GetRadius() << "\n\n";
    
    return 0;
}

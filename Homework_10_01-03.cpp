// 1 - 3. Програма оголлошує клас SimpleCircle, який має конструктор за
//        замовчуванням, додатковий конструктор з ініціалізацією радіусу,
//        деструктор, а також функції "сетер/гетер". Створюється два об'єкти
//        myCircle та myCircleTwo за конст. за замовч. та додатковим відповідно.

#include <iostream>

class SimpleCircle
{
    unsigned short itsRadius = 0;

public:
    SimpleCircle() {};
    SimpleCircle(unsigned short r) : itsRadius(r) {};
    ~SimpleCircle() {};

    unsigned short GetRadius() const { return itsRadius; }
    void SetRadius(unsigned short newRadius) { itsRadius = newRadius; }
};

int main()
{
    SimpleCircle myCircle;
    std::cout << "myCircle created with default constructor and its radius is: "
              << myCircle.GetRadius();
    myCircle.SetRadius(7);
    std::cout << "\nmyCircle radius after SetRadius(7): " << myCircle.GetRadius();
    SimpleCircle myCircleTwo(13);
    std::cout << "\nmyCircleTwo created with custom constructor: "
              << myCircleTwo.GetRadius();
    
    return 0;
}

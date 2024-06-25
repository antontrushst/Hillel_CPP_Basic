// 3. Програма оголошує клас Cat зі звичайною змінною itsAge та статичною
//    змінною HowManyCats. Конструктор цього класу збільшує значення статичної
//    змінної, а деструктор зменшує. Функція main() для наглядності.

#include <iostream>

class Cat
{
    int itsAge;
    static int HowManyCats;

public:
    Cat(int age) : itsAge(age) { HowManyCats++; }
    ~Cat() { HowManyCats--; }
    static int GetNumberOfCats() { return HowManyCats; };
};

int Cat::HowManyCats = 0;

int main()
{
    const int maxCats = 3;
    Cat *CatClub[maxCats];

    for (int i = 0; i < maxCats; i++)
    {
        CatClub[i] = new Cat(i);
        std::cout << "There are " << Cat::GetNumberOfCats() << " cats.\n";
    }

    for (int i = 0; i < maxCats; i++)
    {
        delete CatClub[i];
        std::cout << "There are " << Cat::GetNumberOfCats() << " cats.\n";
    }

    return 0;
}

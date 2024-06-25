/*
    1. - 5. Программа оголошує клас Cat, який має одну статичну змінну і
            декілька нестатичних. Конструктор цього класу збільшує статичну
            змінну, а деструктор зменшує. До кожної змінної клас має функцію
            доступу, які викликаються за допомогою вказівника у тілі функції
            main().
*/

#include <iostream>

class Cat
{
    int itsAge;
    int itsWeight;
    int itsHeight;
    static int HowManyCats;

public:
    Cat(int val)
        : itsAge(val + 4)
        , itsWeight(val + 2)
        , itsHeight(val + 3)
    {
        HowManyCats++;
    }
    ~Cat() { HowManyCats--; }
    static int GetNumberOfCats() { return HowManyCats; };
    int GetAge() const { return itsAge; }
    int GetWeight() const { return itsWeight; }
    int GetHeight() const { return itsHeight; }
};

int Cat::HowManyCats = 0;

int main()
{
    const int maxCats = 3;
    Cat *CatClub[maxCats];

    int (Cat::*pFunc)() const;

    for (int i = 0; i < maxCats; i++)
    {
        CatClub[i] = new Cat(i);
        std::cout << "Here's a new cat!\n";
        pFunc = &Cat::GetAge;
        std::cout << "This cat is " << (CatClub[i]->*pFunc)() << " years old!\n";
        pFunc = &Cat::GetWeight;
        std::cout << "This cat weights " << (CatClub[i]->*pFunc)() << " punds.\n";
        pFunc = &Cat::GetHeight;
        std::cout << "This cat height is " << (CatClub[i]->*pFunc)() << ".\n";
        std::cout << "There are " << Cat::GetNumberOfCats() << " cats.\n\n";
    }

    for (int i = 0; i < maxCats; i++)
    {
        delete CatClub[i];
        std::cout << "There are " << Cat::GetNumberOfCats() << " cats.\n";
    }

    return 0;
}

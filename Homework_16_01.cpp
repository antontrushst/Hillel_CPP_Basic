// 1. Програма оголошує абстрактний клас Vehicle, від якого походять класи
//    Car і Bus. Функція main() демонструє перевантаження та вивід даних
//    у похідних класах.

#include <iostream>

class Vehicle
{
protected:
    std::string itsBrand = {};

public:
    Vehicle() {}
    virtual ~Vehicle() {}
    virtual std::string GetBrand() const = 0;
    virtual void SetBrand(std::string) = 0;
};

class Car : public Vehicle
{
public:
    Car() {}
    ~Car() {}
    std::string GetBrand() const { return itsBrand; }
    void SetBrand(std::string brand) { itsBrand = brand; }
};

class Bus : public Vehicle
{
public:
    Bus() {}
    ~Bus() {}
    std::string GetBrand() const { return itsBrand; }
    void SetBrand(std::string brand) { itsBrand = brand; }
};

int main()
{
    Car aCar;
    Bus aBus;
    aCar.SetBrand("BMW X5");
    aBus.SetBrand("Bogdan A-092");
    std::cout << "aCar brand is: " << aCar.GetBrand() << "\n";
    std::cout << "aBus brand is: " << aBus.GetBrand() << "\n";

    return 0;
}

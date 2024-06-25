/*
    2. Програма оголошує нові класи SportsCar, Wagon і Coupe, які походять з
       класу Car, який в свою чергу тепер є віртуальним з перевантаженими
       методами GetBrand() та SetBrand() від свого базового класу Vehicle.
*/

#include <iostream>

class Vehicle
{
protected:
    std::string itsBrand = {};
public:
    Vehicle(std::string brand) : itsBrand(brand) {}
    virtual ~Vehicle() {}
    virtual std::string GetBrand() const = 0;
    virtual void SetBrand(std::string) = 0;
};

class Car : public Vehicle
{
protected:
    int itsSpeed = 0;
public:
    Car(std::string brand, int speed) : Vehicle(brand), itsSpeed(speed) {}
    virtual ~Car() {}

    virtual int GetSpeed() const = 0;
    virtual std::string GetBrand() const { return itsBrand; }
    virtual void SetBrand(std::string brand) { itsBrand = brand; }
};

class SportsCar : public Car
{
public:
    SportsCar(std::string brand, int speed) : Car(brand, speed) {}
    ~SportsCar() {}
    int GetSpeed() const { return itsSpeed; }
};

class Wagon : public Car
{
public:
    Wagon(std::string brand, int speed) : Car(brand, speed) {}
    ~Wagon() {}
    int GetSpeed() const { return itsSpeed; }
};

class Coupe : public Car
{
public:
    Coupe(std::string brand, int speed) : Car(brand, speed) {}
    ~Coupe() {}
    int GetSpeed() const { return itsSpeed; }
};

int main()
{
    SportsCar aSCar("Porsche", 320);
    Wagon aWagon("Volvo V60", 210);
    Coupe aCoupe("BMW 4", 260);

    std::cout << "aSCar brand is: " << aSCar.GetBrand() << "\n"
              << "aSCar speed is: " << aSCar.GetSpeed() << "\n\n";
    std::cout << "aWagon brand is: " << aWagon.GetBrand() << "\n"
              << "aWagon speed is: " << aWagon.GetSpeed() << "\n\n";
    std::cout << "aCoupe brand is: " << aCoupe.GetBrand() << "\n"
              << "aCoupe speed is: " << aCoupe.GetSpeed() << "\n\n";

    return 0;
}

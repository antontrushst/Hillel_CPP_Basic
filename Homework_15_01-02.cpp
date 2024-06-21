/*
    1. Програма оголошує клас JetPlane, який успадковує класи Rocket і Airplane.
    2. Створено клас Boeing747, який походить від класу JetPlane.

        У функції maini() виводяться всі параметри класів для наглядності.
*/

#include <iostream>

class Rocket
{
protected:
    std::string property_01 = "powerful engine";
    std::string property_02 = "metal body";

public:
    Rocket() {}
    virtual ~Rocket() {}

    virtual std::string GetProperties() const
    {
        return "\t" + property_01 + "\n\t" + property_02 + "\n";
    }
};

class Airplane
{
protected:
    std::string property_01 = "wings";
    std::string property_02 = "pilot seat";

public:
    Airplane() {}
    virtual ~Airplane() {}

    virtual std::string GetProperties() const
    {
        return "\t" + property_01 + "\n\t" + property_02 + "\n";
    }
};

class JetPlane : public Rocket, public Airplane
{
public:
    JetPlane() {}
    virtual ~JetPlane() {}

    virtual std::string GetProperties() const
    {
        return Rocket::GetProperties() + Airplane::GetProperties();
    }
};

class Boeing747 : public JetPlane
{
    std::string propertie_01 = "year of development (1996)";

public:
    Boeing747() {}
    ~Boeing747() {}

    virtual std::string GetProperties() const
    {
        return "\t" + propertie_01 + "\n" + JetPlane::GetProperties();
    }
};

int main()
{
    Rocket rocket;
    Airplane airplane;
    JetPlane jet;
    Boeing747 boeing747;

    std::cout << "\nRocket has:\n" << rocket.GetProperties();
    std::cout << "\nAirplane has:\n" << airplane.GetProperties();
    std::cout << "\nJetPlane has:\n" << jet.GetProperties();
    std::cout << "\nBoeing747 has:\n" << boeing747.GetProperties();

    return 0;
}

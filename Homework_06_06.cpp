// 6. Програма робить все те ж, що і програма з попередніх пунктів ДЗ, але
//    "створення" службовця реалізовано за допомогою конструктора класу зі
//    списком ініціалізації (initializer list), що дозволяє одразу
//    ініціалізувати вік, роки служби та зарплатню службовця.

#include <iostream>

class Employee
{
    unsigned short int age = 0;
    unsigned short int yearsOfService = 0;
    float salary = 0.f;

public:
    Employee(unsigned int itsAge, unsigned int itsYearsOfService, float itsSalary)
        : age(itsAge), yearsOfService(itsYearsOfService), salary(itsSalary) {}

    void Print_Age() const
    {
        std::cout << std::endl << age << " years old.\n";
    }

    void Print_YearsOfService() const
    {
        std::cout << "Years of service: " << yearsOfService << ".\n";
    }

    void Print_Salary()
    {
        std::cout << "They receive $" << salary << ".\n";
    }

    void PrintRounded_Salary() const
    {
        unsigned int iSalary = salary;
        std::cout << "In rounded salary they recieve $"
                  << iSalary - (iSalary % 10) << ".\n";
    }
};

int main()
{
    Employee Manager(34, 7, 2113.5f);
    Employee Cashier(25, 3, 956.3f);

    std::cout << "\nManager";
    Manager.Print_Age();
    Manager.Print_YearsOfService();
    Manager.Print_Salary();
    Manager.PrintRounded_Salary();

    std::cout << "\nCashier";
    Cashier.Print_Age();
    Cashier.Print_YearsOfService();
    Cashier.Print_Salary();
    Cashier.PrintRounded_Salary();

    return 0;
}

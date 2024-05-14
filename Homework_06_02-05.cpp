// 2. - 5. Програма "створює" службовців (Manager та Cashier), ініціалізує їхній
//        вік, роки служби і зарплатню, та виводить цю інформацію в термінал.
//        А також, програма виводить в термінал зарплатню службовця скруглену
//        до $10 (в менший бік).

#include <iostream>

class Employee
{
    unsigned short int age = 0;
    unsigned short int yearsOfService = 0;
    float salary = 0.f;

public:
    void Set_Age(unsigned short int newAge)
    {
        age = newAge;
    }

    void Set_YearsOfService(unsigned short int newYears)
    {
        yearsOfService = newYears;
    }

    void Set_Salary(float newSalary)
    {
        salary = newSalary;
    }

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
    Employee Manager;
    Manager.Set_Age(34);
    Manager.Set_YearsOfService(7);
    Manager.Set_Salary(2113.5f);

    Employee Cashier;
    Cashier.Set_Age(25);
    Cashier.Set_YearsOfService(3);
    Cashier.Set_Salary(956.35f);

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

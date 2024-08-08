// 1-4. Програма приймає вік користувача та за допомогою блоків try і catch
//      виконує перевірку на відповідність введеному значенню до встановлених
//      вимог. У разі виявлення невідповідності програма виконує відповідний
//      блок catch з виводом повідомлення про помилку.

#include <iostream>

class xWrongAge
{
protected:
    float yourAge;
public:
    xWrongAge(float age) : yourAge(age) {}
    virtual ~xWrongAge() {}
    virtual void error_message() const
    {
        std::cout << "You must be between 18 and 79 years old! Access denied!\n";
    }
};

class xTooYoung : public xWrongAge
{
public:
    xTooYoung(float age) : xWrongAge(age) {}
    virtual ~xTooYoung() {}
    virtual void error_message() const
    {
        std::cout << "You're too young! Your age is: " << yourAge << "\n";
        xWrongAge::error_message();
    }
};

class xTooOld : public xWrongAge
{
public:
    xTooOld(float age) : xWrongAge(age) {}
    virtual ~xTooOld() {}
    virtual void error_message() const
    {
        std::cout << "You're too old! Your age is: " << yourAge << "\n";
        xWrongAge::error_message();
    }
};

class xStillTooYoung : public xTooYoung
{
public:
    xStillTooYoung(float age) : xTooYoung(age) {}
    virtual ~xStillTooYoung() {}
    virtual void error_message() const
    {
        std::cout << "Almost there! But still!\n";
        xTooYoung::error_message();
    }
};

class xTooOldAlready : public xTooOld
{
public:
    xTooOldAlready(float age) : xTooOld(age) {}
    virtual ~xTooOldAlready() {}
    virtual void error_message() const
    {
        std::cout << "Sorry, but you're already a grandpa!\n";
        xTooOld::error_message();
    }
};

int main()
{
    float age;
    std::cout << "Enter your age:\n>>> ";
    std::cin >> age;

    try
    {
        if (age == 0)
            throw xWrongAge(age);
        else if (age > 17 && age < 18)
            throw xStillTooYoung(age);
        else if (age < 80 && age > 79)
            throw xTooOldAlready(age);
        else if (age < 18)
            throw xTooYoung(age);
        else if (age > 79)
            throw xTooOld(age);
        else
            std::cout << "Access granted!\n";
    }
    catch (xStillTooYoung error) { error.error_message(); }
    catch (xTooOldAlready error) { error.error_message(); }
    catch (xTooYoung error) { error.error_message(); }
    catch (xTooOld error) { error.error_message(); }
    catch(xWrongAge error) { error.error_message(); }
    catch (...) { std::cout << "Error! Something went wrong!\n"; }

    return 0;
}
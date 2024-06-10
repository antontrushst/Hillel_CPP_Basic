/*
   1. Програма створює два класи Rectangle та Square, який успадковує
      попередній. Обидва класи мають віртуальну фугкцію Clone(), яка
      виконує задачу віртуального конструктора-копіювальника.
      Функція main() демонструє створення та копіювання об'єктів обох
      класів для наглядності.
*/

#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
protected:
    string *itsName;
    int *itsLength;
    int *itsWidth;
public:
    Rectangle(string name, int length, int width)
        : itsName(new string (name))
        , itsLength(new int (length))
        , itsWidth(new int (width)) {}
    virtual ~Rectangle()
    {
        delete itsName;
        delete itsLength;
        delete itsWidth;
        itsName = nullptr;
        itsLength = nullptr;
        itsWidth = nullptr;
    }

    virtual Rectangle* Clone()
    {
        cout << "\nCLONING OBJECT " << *itsName << "...\n";
        return new Rectangle(*this);
    }

    virtual void Print()
    {
        cout << "\nClass: Rectangle\nObject name:" << *itsName << "\n"
             << "Length: " << *itsLength << "\tWidth: " << *itsWidth << "\n";
    }
};

class Square : public Rectangle
{
public:
    Square(string name, int length) : Rectangle(name, length, length) {}
    ~Square()
    {
        delete itsName;
        delete itsLength;
        delete itsWidth;
        itsName = nullptr;
        itsLength = nullptr;
        itsWidth = nullptr;
    }

    Square* Clone() override
    {
        cout << "\nCLONING OBJECT " << *itsName << "...\n";
        return new Square(*this);
    }

    void Print() override
    {
        cout << "\nClass: Square\nObject name:" << *itsName << "\n"
             << "Length: " << *itsLength << "\tWidth: " << *itsWidth << "\n";
    }
};

int main()
{
    Rectangle Rec1("Rec1", 3, 5);
    Rec1.Print();
    Rectangle *Rec1_Copy = Rec1.Clone();
    Rec1_Copy->Print();
    Square Sq1("Sq1", 8);
    Sq1.Print();
    Square *Sq1_Copy = Sq1.Clone();
    Sq1_Copy->Print();
    return 0;
}

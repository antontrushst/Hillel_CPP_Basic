// 8. Програма оголошує клас Square, який успадковує клас Rectangle, який,
//    у свою чергу, успадковує клас Shape.
// 9. Реалізовані конструктори для класів Rectangle та Square, які створюють
//    об'єкти з наданням значень їх змінним itsLength та itsWidth (у функції
//    main() продемонстроване створення таких об'єктів).

#include <iostream>

class Shape
{
};

class Rectangle : public Shape
{
protected:
    int itsLength;
    int itsWidth;
public:
    Rectangle(int length, int width) : itsLength(length), itsWidth(width) {}
    ~Rectangle() {}

    int GetLength() const { return itsLength; }
    int GetWidth() const { return itsWidth; }
};

class Square : public Rectangle
{
public:
    Square(int length) : Rectangle(length, length) {}
    ~Square() {}
};

int main()
{
    Rectangle Rec1(4, 7);
    std::cout << "Rec1 length is: " << Rec1.GetLength() << "\n";
    std::cout << "Rec1 width is: " << Rec1.GetWidth() << "\n";
    Square Sqr1(3);
    std::cout << "Sqr1 side length is: " << Sqr1.GetLength() << "\n";
    return 0;
}

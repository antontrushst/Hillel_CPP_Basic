/*
    1. Кількість елементів у зв'язному списку обмежена тільки об'ємом пам'яті
       комп'ютера.
    2. Ні, зв'язні списки не підтримують індекси.
    3. У рядку "Сергій - хороший хлопець" останнім символом є \0 -
       null-terminator, який не видно користувачеві, але ним позначено кінець
       рядка для компілятора.
    4. Код нижче оголошує клас вузлв Node, який підтримує цілі числа.
*/

class Node
{
    int *myData;
    Node *myNext;
public:
    Node(int data, Node *next) : myData(new int(data)), myNext(next) {}
    virtual ~Node()
    {
        delete myData;
        myData = nullptr;
        delete myNext;
        myNext = nullptr;
    }
    virtual int GetData() const { return *myData; }
};

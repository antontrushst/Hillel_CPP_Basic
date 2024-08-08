// 5. Окрім того, що компілятор не дав мені збілдити програму без додавання
//    #include <cstring> для роботи strcpy, помилка полягає в тому, що при
//    виявленні ситуації нестачі пам'яті програма створює масив char[20]
//    для виведення повідомлення про помилку. Ми не можемо створити подібне
//    повідомлення, якщо у нас закінчилась пам'ять.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class xOutOfMemory
{
public:
    xOutOfMemory()
    {
        theMsg = new char[20];
        strcpy(theMsg, "error in memory");
    }
    ~xOutOfMemory()
    {
        delete[] theMsg;
        cout << "Memory restored. " << endl;
    }
    char *Message() { return theMsg; }

private:
    char *theMsg;
};

int main()
{
    try
    {
        char *var = new char;
        if (var == nullptr)
        {
            xOutOfMemory *px = new xOutOfMemory;
            throw px;
        }
    }
    catch (xOutOfMemory *theException)
    {
        cout << theException->Message() << endl;
        delete theException;
    }
    return 0;
}

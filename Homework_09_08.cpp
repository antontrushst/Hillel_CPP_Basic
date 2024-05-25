// 8. Дана програма має функцію MakeCat(), що повертає посилання на виділену
//    динамічну пам'ять (heap), яка містить новостворений об'єкт класу Cat.
//    Оскільки в результаті цієї функції ми створюємо посилання, то в подальшому
//    видалення цього блоку пам'яті призведе до невизначенності нашої програми,
//    про що компілятор повідомляє попередженням (при спробі звільнення пам'яті).

#include <iostream>

using namespace std;

class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat &MakeCat(int age);

int main()
{
	int age = 7;
	Cat Boots = MakeCat(age);
	cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
	return 0;
}

Cat &MakeCat(int age)
{
	Cat *pCat = new Cat(age);
	return *pCat;
}

// 5. Рядок 25 має оголошення дружнього класу всередині функції, що є помилкою.

#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal &, int);

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
	friend class Animal;
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}

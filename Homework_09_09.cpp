// 9. Це виправленна версія програми з попереднього завдання. Переписана функція
//    MakeCat() тепер повертає вказівник замість посилання, що дозволяє в
//    подальшому звільнити цей блок пам'яті (що також дописаноо в код для
//    наглядності).

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

Cat *MakeCat(int age);

int main()
{
	int age = 7;
	Cat *Boots = MakeCat(age);
	cout << "Boots is: " << Boots->GetAge() << " years old" << endl;

	delete Boots;
	Boots = nullptr;
	
	return 0;
}

Cat *MakeCat(int age)
{
	Cat *pCat = new Cat(age);
	return pCat;
}

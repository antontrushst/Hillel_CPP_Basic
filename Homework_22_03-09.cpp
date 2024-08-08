// 3. Виконання шаблонної версії класу List.

// 4. Функція main() містить приклад списків з int, string та об'єктами Cat.

// 5. Відповідь: На відміну від типу int, об'єкт скласу Cat може мати безліч
//    параметрів, за якими можна перевіряти наявність конкретного об'єкту в
//    списку. Функція is_present() потребуватиме спеціалізації до класу Cat
//    для успішного виконання.

// 6-7. Рядки 73-74 та 87-88 містять оголошення дружньої функції
//      перевантаженного оператора == . Рядки 200-242 містять визначення
//      цієї функції та спеціалізацію до класу Cat. Функція main() містить
//      демонстрацію роботи данної функції.

// 8. Так, дружня функція перевантаження оператора == має ту ж вимогу
//    до специалізації до класу Cat, що і функція is_present().

// 9. Рядок 76 містить оголошення функції swap(), що обмінює данні двох
//    змінних у списку між собою. Рядки 244-281 містять визнічення цієї
//    функції, а також спеціалізовану версію до класу Cat. Функція main()
//    демонструє виконання данної функції.

#include <iostream>
#include <string>

class Cat
{
	int itsWeight;
	std::string itsName;

public:
	Cat(std::string name, int weight) : itsName(name), itsWeight(weight) {}
	~Cat() {}
	std::string print() const
	{
		return itsName + " " + std::to_string(itsWeight) + "kg";
	}
	std::string getName() const {return itsName;}
	int getWeight() const {return itsWeight;}

};

template <class T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value, int pos);
	void append(T value);
	bool is_present(T value) const;
	bool is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
	void showAll() const
	{
        if (is_empty())
        {
            std::cout << "The list is empty!\n";
            return;
        }
		ListCell *pTemp = head;
		for (int i = 0; i < theCount; i++)
		{
			std::cout << "Pos " << i << ": " << pTemp->val << "\n";
			pTemp = pTemp->next;
		}
		pTemp = nullptr;
	}

	template <typename U>
	friend bool operator == (List<U> &lhs, List<U> &rhs);

	void swap(int pos1, int pos2);

private:
	class ListCell
	{
	public:
    	ListCell(T value, ListCell *cell = 0) : val(value),
                                              	next(cell) {}
    	T val;
    	ListCell *next;

		template <typename U>
		friend bool operator == (List<U> &lhs, List<U> &rhs);
	};
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

template <class T>
List<T>::~List()
{
	next = head;
	while (true)
	{
        if (is_empty())
            break;
		if (next->next == nullptr)
			break;
		next = next->next;
		delete head;
		head = next;
	}

	head = nullptr;
	next = nullptr;
}

template <class T>
void List<T>::insert(T value, int pos)
{
	if (is_empty())
	{
		// tail = new ListCell(0);
		next = new ListCell(value, tail);
		head = next;
	}
	else if (pos == 0)
	{
		next = new ListCell(value, head);
		head = next;
	}
	else
	{
		if (pos >= theCount)
		{
			std::cerr << "Out of scope!\n";
			return;
		}
		next = head;
		int offset = pos;
		while (offset != 0)
		{
			next = next->next;
			offset--;
		}
		ListCell *pTemp = next;
		next = new ListCell(value, next->next);
		pTemp->next = next;
		pTemp = nullptr;
	}
	theCount++;
}

template <class T>
void List<T>::append(T value)
{
	insert(value, theCount - 1);
}

template <class T>
bool List<T>::is_present(T value) const
{
	ListCell *pTemp = head;
	while (pTemp != tail)
	{
		if (pTemp->val == value)
			return 1;
		pTemp = pTemp->next;
	}
	return 0;
}

template <>
void List<Cat>::showAll() const
{
	if (is_empty())
	{
		std::cout << "The list is empty!\n";
		return;
	}
	ListCell *pTemp = head;
	for (int i = 0; i < theCount; i++)
	{
		std::cout << "Pos " << i << ": " << pTemp->val.print() << "\n";
		pTemp = pTemp->next;
	}
	pTemp = nullptr;
}

template <>
bool List<Cat>::is_present(Cat cat) const
{
	ListCell *pTemp = head;
	while (pTemp != tail)
	{
		if (pTemp->val.getName() == cat.getName() && pTemp->val.getWeight() == cat.getWeight())
			return true;
		pTemp = pTemp->next;
	}
	return false;
}

template <typename U>
bool operator == (List<U> &lhs, List<U> &rhs)
{
	if (lhs.theCount != rhs.theCount)
		return false;

	lhs.next = lhs.head;
	rhs.next = rhs.head;

	for (int i = 0; i < lhs.theCount; i++)
	{
		if (lhs.next == rhs.next)
			return true;
		if (lhs.next->val != rhs.next->val)
			return false;
		lhs.next = lhs.next->next;
		rhs.next = rhs.next->next;
	}
	return true;
}

template <>
bool operator == (List<Cat> &lhs, List<Cat> &rhs)
{
	if (lhs.theCount != rhs.theCount)
		return false;

	lhs.next = lhs.head;
	rhs.next = rhs.head;

	for (int i = 0; i < lhs.theCount; i++)
	{
		if (lhs.next == rhs.next)
			return true;
		if (lhs.next->val.getName() != rhs.next->val.getName())
			return false;
		if (lhs.next->val.getWeight() != rhs.next->val.getWeight())
			return false;
		lhs.next = lhs.next->next;
		rhs.next = rhs.next->next;
	}
	return true;
}

template <class T>
void List<T>::swap(int pos1, int pos2)
{
	ListCell *cell_1 = head;
	ListCell *cell_2 = head;

	for (int i = pos1; i > 0; i--)
		cell_1 = cell_1->next;
	for (int i = pos2; i > 0; i--)
		cell_2 = cell_2->next;

	T temp;
	temp = cell_1->val;
	cell_1->val = cell_2->val;
	cell_2->val = temp;

	cell_1 = nullptr;
	cell_2 = nullptr;
}

template <>
void List<Cat>::swap(int pos1, int pos2)
{
	ListCell *cell_1 = head;
	ListCell *cell_2 = head;

	for (int i = pos1; i > 0; i--)
		cell_1 = cell_1->next;
	for (int i = pos2; i > 0; i--)
		cell_2 = cell_2->next;

	Cat temp(cell_1->val.getName(), cell_1->val.getWeight());
	cell_1->val = cell_2->val;
	cell_2->val = temp;

	cell_1 = nullptr;
	cell_2 = nullptr;
}

int main()
{
    std::cout << "String List:\n";
	List<std::string> stringList;
	stringList.insert("My", 0);
	stringList.insert("Hi!", 0);
	stringList.insert("name", 1);
	stringList.insert("is", 2);
	stringList.append("Anton!");
	stringList.append("_");
	stringList.showAll();
	std::cout << "Is there \"Anton!\" in this list? -> "
			  << std::boolalpha << stringList.is_present("Anton!") << "\n";
	std::cout << "Is there \"bye\" in this list? -> "
			  << std::boolalpha << stringList.is_present("bye") << "\n\n";

	std::cout << "String List pos 2 and pos 5 swapped:\n";
	stringList.swap(2, 5);
	stringList.showAll();
	std::cout << "\n";

    std::cout << "Int List_1:\n";
    List<int> intList_1;
	intList_1.insert(3, 0);
	intList_1.insert(5, 0);
	intList_1.insert(4, 1);
	intList_1.insert(16, 2);
	intList_1.append(38);
	intList_1.append(22);
	intList_1.showAll();
	std::cout << "Is there \"38\" in this list? -> "
			  << std::boolalpha << intList_1.is_present(38) << "\n";
	std::cout << "Is there \"48\" in this list? -> "
			  << std::boolalpha << intList_1.is_present(48) << "\n\n";

	std::cout << "Int List_2:\n";
    List<int> intList_2;
	intList_2.insert(3, 0);
	intList_2.insert(5, 0);
	intList_2.insert(8, 1);
	intList_2.insert(16, 2);
	intList_2.append(38);
	intList_2.append(22);
	intList_2.showAll();

	bool isIntListsEqual = intList_1 == intList_2;
	std::cout << "Are intList_1 and intList_2 equal? -> "
			  << std::boolalpha << isIntListsEqual << "\n\n";

    std::cout << "Cat List_1:\n";
    List<Cat> catList_1;
    catList_1.insert(Cat("Frisky", 3), 0);
	catList_1.insert(Cat("Thomas", 4), 0);
	catList_1.insert(Cat("Lilly", 2), 1);
	catList_1.append(Cat("Billy", 4));
	catList_1.showAll();
	std::cout << "Is there cat named Thomas that weights 4kg in this list? -> "
			  << std::boolalpha << catList_1.is_present(Cat("Thomas", 4)) << "\n";
	std::cout << "Is there cat named Frisky that weights 2kg in this list? -> "
			  << std::boolalpha << catList_1.is_present(Cat("Frisky", 2)) << "\n\n";

    std::cout << "Cat List_2:\n";
    List<Cat> catList_2;
    catList_2.insert(Cat("Frisky", 3), 0);
	catList_2.insert(Cat("Thomas", 4), 0);
	catList_2.insert(Cat("Lilly", 2), 1);
	catList_2.append(Cat("Billy", 4));
	catList_2.showAll();
	bool isCatListsEqual = catList_1 == catList_2;
	std::cout << "Are catList_1 and catList_2 equal? -> "
			  << std::boolalpha << isCatListsEqual << "\n\n";

	std::cout << "Cat List pos 2 and pos 3 swapped: \n";
	catList_2.swap(2, 3);
	catList_2.showAll();

	return 0;
}
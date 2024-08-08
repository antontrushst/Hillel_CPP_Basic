// 2. Виконання звичайної (не щаблонної) версії класу List з повноцінним
//    функціоналом. Функція main() містить кілька викликів функцій класу
//    для демонстрації роботи.

#include <iostream>

class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(int value, int pos);
	void append(int value);
	bool is_present(int value) const;
	bool is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
	void showAll() const
	{
		ListCell *pTemp = head;
		for (int i = 0; i < theCount; i++)
		{
			std::cout << "Pos " << i << ": " << pTemp->val << "\n";
			pTemp = pTemp->next;
		}
		pTemp = nullptr;
	}
private:
	class ListCell
	{
	public:
    	ListCell(int value, ListCell *cell = 0) : val(value),
                                              	next(cell) {}
    	int val;
    	ListCell *next;
	};
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

List::~List()
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

void List::insert(int value, int pos = 0)
{
	if (is_empty())
	{
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

void List::append(int value)
{
	insert(value, theCount - 1);
}

bool List::is_present(int value) const
{
	ListCell *pTemp = head;
	while (pTemp != tail)
	{
		if (pTemp->val == value)
			return true;
		pTemp = pTemp->next;
	}
	return false;
}

int main()
{
	List list;
	list.insert(3);
	list.insert(5);
	list.insert(4, 1);
	list.insert(16, 2);
	list.append(38);
	list.append(22);
	list.showAll();
	std::cout << std::boolalpha << list.is_present(38) << std::endl;
	std::cout << std::boolalpha << list.is_present(48) << std::endl;
	return 0;
}
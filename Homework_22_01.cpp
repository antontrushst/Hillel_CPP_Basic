// 1. Клас List змінений на шаблон

template <class T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value);
	void append(T value);
	T is_present(T value) const;
	int is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
private:
	class ListCell
	{
	public:
    	ListCell(T value, ListCell *cell = 0) : val(value),
                                              	next(cell) {}
    	T val;
    	ListCell *next;
	};
	T val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

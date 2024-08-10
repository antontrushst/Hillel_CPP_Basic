// Дана програма представляє виконання мого власного контейнера

#include <iostream>

template <class T>
class container
{
public:
    container() : p_Head(nullptr), p_Tail(nullptr), elementCounter(0) {}
    ~container()
    {
        while (p_Head != p_Tail)
        {
            node *p_temp = p_Head->p_Next;
            delete p_Head;
            p_Head = p_temp;
        }
        p_Head = nullptr;
    }


    T& front();
    T& back();
    void push_front(T value);
    void push_back(T value);
    void insert(T value, int position);
    void pop_front();
    void pop_back();
    void clear();
    int  size()  const {return elementCounter;};
    bool empty() const {return size() == 0;};
    void print() const;


    struct iterator
    {
        iterator() {}
        iterator(T *val) : value(val) {}

        T& getValue() const {return *value;}
        T* getPointer() const {return value;}

    private:
        T *value;
    };
    
    iterator begin() { return iterator(&p_Head->value); }
    iterator end()   { return iterator(&p_Tail->value); }

private:
    struct node
    {
        node(T val, node *prev, node *next)
            : value(val)
            , p_Previous(prev)
            , p_Next(next) {}

        T  value;
        node *p_Previous;
        node *p_Next;
    };

    node *p_Head;
    node *p_Tail;
    int   elementCounter;

    struct xEmpty
    {
        void error_message() {std::cout << "ERROR: Container is empty!\n";}
    };

    struct xOutOfBoundary
    {
        void error_message() {std::cout << "ERROR: insert() position is "
                                        << "out of boundary!\n";}
    };
};

// Повертає перший елемент контейнера   ////////////////////////////////////////
template <class T>
T& container<T>::front()
{
    // виведи повідомлення про помилку та екстренно заверши
    // виконання програми, якщо контейнер порожній .............................
    try   { if (empty()) { throw xEmpty(); } }
    catch (xEmpty error) { error.error_message(); exit(1); }

    return p_Head->value;
}

// Повертає останній елемент контейнера   //////////////////////////////////////
template <class T>
T& container<T>::back()
{
    // виведи повідомлення про помилку та екстренно заверши
    // виконання програми, якщо контейнер порожній .............................
    try   { if (empty()) { throw xEmpty(); } }
    catch (xEmpty error) { error.error_message(); exit(1); }

    node *p_temp = p_Head;
    for (int i(0); i < size() - 1; i++)
        p_temp = p_temp->p_Next;

    return p_temp->value;
}

// Додає елемент в початок контейнера   ////////////////////////////////////////
template <class T>
void container<T>::push_front(T value)
{
    if (empty())
        p_Head = new node(value, nullptr, p_Tail);
    else
    {
        // створи вказівник на попередній перший елемент .......................
        node *p_temp = p_Head;

        // створи новий перший елемент контейнера ..............................
        p_Head = new node(value, nullptr, p_temp);

        // зміни вказівник попереднього першого елемента
        // на новий перший елемент контейнера ..................................
        p_temp->p_Previous = p_Head;
    }
    
    elementCounter++;
}

// Додає елемент в кінець контейнера   /////////////////////////////////////////
template <class T>
void container<T>::push_back(T value)
{
    if (empty())
        push_front(value);
    else
    {
        node *p_temp = p_Head;

        // дійди до останнього елемента ........................................
        for (int i(0); i < size() - 1; i++)
            p_temp = p_temp->p_Next;

        // створи новий елемент та задай йому відповідні вказівники ............
        node *p_newNode = new node(value, p_temp, p_Tail);

        // зміни вказівник попереднього останнього елемента
        // на новий останній елемент контейнера.................................
        p_temp->p_Next  = p_newNode;
    }

    elementCounter++;
}

// Вставляє елемент в контейнер перед вказанною позицією   /////////////////////
template <class T>
void container<T>::insert(T value, int position)
{
    // виведи повідомлення про помилку та екстренно заверши виконання
    // програми, якщо вказане положення за межами контейнера ...................
    try
    {
        if (position < 0 || position >= size() && size() != 0)
            throw xOutOfBoundary();
    }
    catch (xOutOfBoundary error) { error.error_message(); exit(1); }

    if (empty() || position == 0)
        push_front(value);
    else
    {
        // створи вказівник та проведи його по елементам контейнера до
        // елемента на заданій позиції..........................................
        node *p_temp = p_Head;
        for (int i(0); i < position; i++)
            p_temp = p_temp->p_Next;

        // створи вказівник на попередній від поточного елемент, а також
        // новий елемент контейнера з відповідними вказівниками ................
        node *p_previous   = p_temp->p_Previous;
        node *p_newElement = new node(value, p_previous, p_temp);

        // зміни вказівники попереднього та наступного елементів
        // відповідно до нового елемента контейнера ............................
        p_temp->p_Previous = p_newElement;
        p_previous->p_Next = p_newElement;

        elementCounter++;
    }
}

// Видаляє перший елемент контейнера   /////////////////////////////////////////
template <class T>
void container<T>::pop_front()
{
    if (empty())
        std::cout << "pop_front(): Container is empty!\n";
    else if (size() == 1)
        clear();
    else
    {
        // створи вказівник на другий елемент контейнера
        // та зануль його вказівник на попередній елемент ......................
        node *p_temp = p_Head->p_Next;
        p_temp->p_Previous = nullptr;

        // видали перший елемент та познач головою контейнера
        // другий елемент ......................................................
        delete p_Head;
        p_Head = p_temp;

        elementCounter--;
    }
}

// Видаляє останній елемент контейнера   ///////////////////////////////////////
template <class T>
void container<T>::pop_back()
{
    if (empty())
        std::cout << "pop_back(): Container is empty!\n";
    else if (size() == 1)
        clear();
    else
    {
        // створи тимчасовий вказівник та пройдись по елементам
        // контейнера допоки він не стане вказувати на останній елемент ........
        node *p_temp = p_Head;
        for (int i(0); i < size() - 1; i++)
            p_temp = p_temp->p_Next;

        // створи ще один тимчасовий вказівник, який вказуватиме на
        // передостанній елемент контейнера, та познач його останнім ...........
        node *p_newLast = p_temp->p_Previous;
        p_newLast->p_Next = p_Tail;

        // видали елемент, що раніше був останнім ..............................
        delete p_temp;

        elementCounter--;
    }
}

// Очищує контейнер  //////////////////////////////////////////////////////////
template <class T>
void container<T>::clear()
{
    if (empty())
        std::cout << "clear(): Container is empty!\n";
    else
    {
        // створи вказівник на другий елемент контейнера
        // та видали перший елемент ............................................
        node *p_temp = p_Head->p_Next;
        delete p_Head;

        // пройдись по всім іншим елементам та видали їх .......................
        for (int i(0); i < size() - 1; i++)
        {
            p_Head = p_temp;
            p_temp = p_temp->p_Next;
            delete p_Head;
        }

        // зануль вказівник голови контейнера та
        // встанови лічильник елементів на нуль ................................
        p_Head = nullptr;
        elementCounter = 0;
    }
}

// Виводить в термінал вміст контейнера   //////////////////////////////////////
template <class T>
void container<T>::print() const
{
    if (empty())
        std::cout << "print(): Container is empty!\n";
    else
    {
        // створи вказівник, який пройдеться по всім елементам контейнера,
        // починаючи з голови, та виведе їх в термінал .........................
        node *p_temp = p_Head;
        for (int i(0); i < size(); i++)
        {
            std::cout << "Index " << i << ": " << p_temp->value << "\n";
            p_temp = p_temp->p_Next;
        }
    }
}

int main()
{
    container<int> myContainer;
    std::cout << "Creating container... Adding a few elements...\n";
    myContainer.push_front(15);
    myContainer.push_front(6);
    myContainer.push_back(22);
    myContainer.push_back(64);
    myContainer.push_front(88);
    myContainer.push_back(77);
    myContainer.print();
    std::cout << std::endl;

    std::cout << "Deleting a few elements from container...\n";
    myContainer.pop_front();
    myContainer.pop_back();
    myContainer.print();
    std::cout << std::endl;

    std::cout << "Inserting some elements into container...\n";
    myContainer.insert(112, 1);
    myContainer.insert(567, 4);
    myContainer.insert(111, 0);
    myContainer.print();
    std::cout << std::endl;

    std::cout << "Printing container size and its begin() iterator...\n";
    std::cout << "Container size is: " << myContainer.size() << "\n";
    container<int>::iterator it;
    it = myContainer.begin();
    std::cout << "Begin iterator address is: " << it.getPointer() << "\n";
    std::cout << "Begin iterator value is: " << it.getValue() << "\n";
    std::cout << std::endl;

    std::cout << "Clearing the container...\n";
    myContainer.clear();
    myContainer.print();
    
    return 0;
}
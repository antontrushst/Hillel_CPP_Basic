// 8. Відсутній вказівник доступу public для методу GetAge(), що робить його
//    недоступним для використання поза класом.

class Cat
{
    int GetAge() const;

private:
    int itsAge;
};

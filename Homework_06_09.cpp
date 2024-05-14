// 9. 1 - функція main() не може дати значення змінній itsStation, оскільки
//        ця змінна оголошена приватною для класу TV;
//    2 - у рядку 21 функція звертається до назви класу, а не назви об'єкта
//        цього класу, що є помилкою;
//    3 - об'єкт myOtherTV(2) не може бути створений з ініціалізацією, бо
//        необхідного для цього конструктора склас TV не має;

class TV
{
public:
    void SetStation(int Station);
    int GetStation() const;

private:
    int itsStation;
};
main()
{
    TV myTV;
    myTV.itsStation = 9;
    TV.SetStation(10);
    TV myOtherTV(2);
}

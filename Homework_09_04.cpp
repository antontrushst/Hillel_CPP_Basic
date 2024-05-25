// 4. Дана програма створює блукаючий вказівник.
// 5. Для виправлення блукаючого вказівника необхідно розкоментувати рядок 9.

int main()
{
    int *strayPointer = new int;
    *strayPointer = 13;
    delete strayPointer;
    // strayPointer = nullptr;
    
    return 0;
}

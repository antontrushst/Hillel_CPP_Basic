// 6. Програма виконує функцію memLeak(), яка призводить до витоку пам'яті.
// 7. Для виправлення витоку пам'яті необхідно розкоментувати рядок 7.

void memLeak()
{
    int *pointer = new int(3);
    // delete pointer;
}

int main()
{
    memLeak();

    return 0;
}

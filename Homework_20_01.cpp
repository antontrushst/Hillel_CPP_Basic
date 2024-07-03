// 1. Програма приймає ім'я файлу в якості аргумента та виводить в термінал
//    лише текстові символи та розділові знаки (включаючи цифри, круглі дужки,
//    лапки та двокрапку і крапку з комою). Алгоритм сортування символів
//    використовує таблицю ASCII.

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    char temp;
    while (fin >> temp)
    {
        if (temp >= 'A' && temp <= 'Z' || temp >= 'a'  && temp <= 'z' ||
            temp >= ' ' && temp <= '"' || temp >= '\'' && temp <= ')' ||
            temp >= ',' && temp <= '.' || temp >= '0'  && temp <= ';')
            std::cout << temp;
    }
    fin.close();

    return 0;
}

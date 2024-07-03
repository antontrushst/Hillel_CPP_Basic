// 2. Програма виводить в термінал задані до неї аргументи у зворотньому порядку,
//    оминаючи назву програми.

#include <iostream>

int main(int argc, char* argv[])
{
    for (int i = argc; i > 1; i--)
        std::cout << argv[i - 1] << "\n";

    return 0;
}

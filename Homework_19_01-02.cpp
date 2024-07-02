// 1. - 2. Програма виводить повідомлення на початку та в кінці роботи (clog),
//         запитує повне ім'я в користувача (cout), приймає введення від
//         користувача включаючи пробіли (cin.get) та виводить повідомлення
//         про помилку, якщо введено суцільний текст (cerr).

#include <iostream>

int main()
{
    std::clog << "Strarting the program...\n"   << std::endl;

    char fullName[255];
    std::cout << "Enter your full name, please:" << std::endl;
    std::cin.get(fullName, 255);

    for (char c : fullName)
    {
        if (c == ' ')
        {
            std::cout << "Here's your full name: " << fullName << std::endl;
            break;
        }
        else if (c == '\0')
        {
            std::cerr << "ERROR: Full name must include at least one space "
                      << "between first and last name!" << std::endl;
            break;
        }
    }

    std::clog << "\nExiting the program..." << std::endl;

    return 0;
}
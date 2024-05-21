// 5. Дана програма оголошує вказівник pInt, який не ініціалізований ні як
//    nullptr (що недобре), ні як адреса до пім'яті змінної, що створює помилку
//    відому як undefined behaviour.

#include <iostream>

using namespace std;

int main()
{
	int *pInt;
	*pInt = 9;
	cout << " The value at pInt: "<< *pInt;

	return 0;
}


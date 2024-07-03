// 3. Відсутнє зазначення простору імені std для функцій cout та endl.

#include <iostream>

int main()
{
	cout << "Hello world!" << endl;
	return 0;
}

/*
    4. Варіанти усунення помилки:
        1)  зазначати простір імені std при кожному виклику його функцій
            std::cout << "Hello world!" << std::endl;

        2)  вказати використання простору імені std глобально, або локально
            на початку фукції main()
            using namespace std;

        3)  вказати використання окремих функцій з їх простором імені
            using std::cout;
            using std::endl;
*/ 
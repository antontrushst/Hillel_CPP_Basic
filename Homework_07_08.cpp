// 8. Даний цикл ніколи не буде виконуватись, бо початкова умова є false,
//    а зміна лічильника вкладена у тіло самого циклу.

int counter = 100;
while (counter < 10)
{
	cout << "counter now: " << counter;
	counter--;
}

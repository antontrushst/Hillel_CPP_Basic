// 3. Даний код має переплутані межі для циклів, що ітерують по двовимірному
//    масиву SomeArray[], через що змінна j в другому циклі виходить за межі
//    масиву.

	unsigned short SomeArray[5][4];
	for (int i = 0; i < 4; i++)
    		for (int j = 0; j < 5; j++)
        			SomeArray[i][j] = i + j;
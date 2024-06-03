// 6. - повертаємий об'єкт має бути референсом, отже в рядку 6 після першого
//      SQUARE необхідно додати знак &
//    - рядок 8 повністю зайвий
//    - в кінці рядка 10 стоїть : замість необхідного ;

SQUARE SQUARE::operator=(const SQUARE &rhs)
{
	itsSide = new int;
	*itsSide = rhs.GetSide();
	return *this:
}

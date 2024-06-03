// 7. В рядку 4 необхідно зробити повертаємий тип референсом, отже додати знак
//    & пасля оголонення типу VeryShort.

VeryShort VeryShort::operator+(const VeryShort &rhs)
{
	itsVal += rhs.GetItsVal();
	return *this;
}

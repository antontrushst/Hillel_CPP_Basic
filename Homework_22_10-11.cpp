// 10-11. Лістинг переписаний таким чином, щоб виконувати клас SchoolClass
//        як список з додаванням студентів за допомогою push_back().
//        Також дописаний фанктор (об'єкт функції) ShowStudentInfo, який
//        використовується у функції ShowVector() для виведення інформації
//        про кожного студента.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
	Student();
	Student(const string &name, const int age);
	Student(const Student &rhs);
	~Student();

	void SetName(const string &name);
	string GetName() const;
	void SetAge(const int age);
	int GetAge() const;
	Student &operator=(const Student &rhs);

private:
	string itsName;
	int itsAge;
};

Student::Student()
	: itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
									   itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
	itsName = name;
}

string Student::GetName() const
{
	return itsName;
}

void Student::SetAge(const int age)
{
	itsAge = age;
}

int Student::GetAge() const
{
	return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}

ostream &operator<<(ostream &os, const Student &rhs)
{
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}

template <class T>
void ShowVector(const vector<T> &v); // Відображає властивості вектора
class ShowStudentInfo
{
    // string itsName;
    // int itsAge;

public:
    ShowStudentInfo() {}
    // ShowStudentInfo(Student &s) : itsName(s.GetName()), itsAge(s.GetAge()) {}
    void operator () (Student &st) const
    {
        std::cout << st.GetName() << " is " << st.GetAge() << " years old\n";
    }
};

typedef vector<Student> SchoolClass;

int main()
{
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);

	SchoolClass myClass;
    myClass.push_back(Harry);
    myClass.push_back(Sally);
    myClass.push_back(Bill);
    myClass.push_back(Peter);
    
    ShowVector(myClass);

    for (auto& student : myClass)
        student.SetAge(student.GetAge() + 1);

    ShowVector(myClass);

	return 0;
}

//
// Відображає властивості вектора
//
template <class T>
void ShowVector(const vector<T> &v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t " << (v.empty() ? "empty" : "not empty");
	cout << "\n";
    ShowStudentInfo show;
	for (auto student : v)
		show(student);
	cout << endl;
}
////
// EmptyClass:
// max_size() = 576460752303423487 size() = 0      capacity() = 0   empty

// GrowingClass(3):
// max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
// New Student is 16 years old
// New Student is 16 years old
// New Student is 16 years old

// GrowingClass(3) after assigning students:
// max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
// New Student is 16 years old
// Sally is 15 years old
// Bill is 17 years old

// GrowingClass() after aded 4ht student:
// max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
// New Student is 16 years old
// Sally is 15 years old
// Bill is 17 years old
// Peter is 16 years old

// GrowingClass() after Set:
// max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
// Harry is 18 years old
// Sally is 15 years old
// Bill is 17 years old
// Peter is 16 years old


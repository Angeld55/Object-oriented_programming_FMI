#include <iostream>
#include <memory> 

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	Test(const Test& other)
	{
		cout << "Copy constructor" << endl;
	}
	Test& operator=(const Test& other)
	{
		cout << "Assignment operator" << endl;
	}
	~Test()
	{
		cout << "Detructor" << endl;
	}

};
int main()
{


	shared_ptr<Test> smart_pointer_1(new Test());

	cout << smart_pointer_1.get() << endl; //адресът на обекта.

	shared_ptr<Test> smart_pointer_2(smart_pointer_1);

	cout << smart_pointer_1.get() << endl; //За разлика от uniqe_ptr тук smart_pointer_1 ПРОДЪЛЖАВА да сочи към обекта.  

	cout << smart_pointer_2.use_count() << endl; //може да видим колко пойнтера са насочени към обекта.
	// Обектът ще се изтрие, когато пойнтерите станат 0.


	{
		shared_ptr<Test> smart_pointer_3 = smart_pointer_2;

		cout << smart_pointer_1.use_count() << endl; //3 пойнтера към обекта ни.

	}
	cout << smart_pointer_1.use_count() << endl; // 2, защото smart_pointer_3 вече го няма.

	return 0;
} //тук изчезват пойнтерите -> броят им става 0 и обекта се изтрива(изтрива се от последния пойнтер преди да изчезне)
//Възможно е да се получи цикличност. Един shared_ptr да реферира друг shared_ptr, който обратно да реферира първия! Как да се справим с проблема ще видим в точка 3. (weak_ptr)

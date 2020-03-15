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
	void f()
	{

	}

};
int main()
{


	shared_ptr<Test> smart_pointer_1(new Test());

	cout << smart_pointer_1.get() << endl; //адресът на обекта.

	weak_ptr<Test> smart_pointer_2(smart_pointer_1);

	cout << smart_pointer_2.use_count() << endl;  // 1 - weak_ptr НЕ участва в бройката на пойнтерите към обектите.

	//smart_pointer_2->f(); ГРЕШКА!	    
	//Това е само за временно пазане на адреса! НЕ МОЖЕМ да достъпим данните. Ако искате да достъпите данните на този пойнтер трябва да го превърнете(заключте) в shared_ptr!. 

	shared_ptr<Test> smart_pointer_3 = smart_pointer_2.lock(); //.lock() връща shared_ptr към обекта.

	cout << smart_pointer_1.use_count() << endl;//2

	smart_pointer_3->f(); // .. и тн.

}

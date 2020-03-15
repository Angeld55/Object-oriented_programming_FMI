/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
	//Това е само за временен достъп! Ако искате да достъпите данните на този пойнтер трябва да го превърнете в shared_ptr!.

	shared_ptr<Test> smart_pointer_3 = smart_pointer_2.lock();

	cout << smart_pointer_1.use_count() << endl;//2

	smart_pointer_3->f(); // .. и тн.

}

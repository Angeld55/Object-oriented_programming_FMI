
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
	{
		auto_ptr<Test> smart_pointer_1(new Test()); //Test()

		Test* obj = smart_pointer_1.get(); //От тук иматаме достъп до паметта, към която сочи пойнтера.
		//delete obj; // Това не трябва да се прави! smart_pointer_1 не знае, че паметта е освободена и ще се опита да я освободи, което ще доведе до грешка!

	}  //Test  (Паметта се освобождава сама)

	{
	auto_ptr<Test> smart_pointer_2(new Test());


	auto_ptr<Test> smart_pointer_3(smart_pointer_2);

	smart_pointer_2.get(); // Това ще даде NULL, защото smart_pointer_3 "открадна" обекта на smart_pointer_2  
}


	return 0;
}

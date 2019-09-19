#include "Figure.h"


int main()
{
	Figure** arr= new Figure*[3];
	arr[0] = new Triangle(15, 15, 15, 30, 50, 30);
	arr[1] = new Rectangle(15, 15, 50, 30);
	arr[2] = new Circle(1, 2, 9);

	for (int i = 0; i < 3; i++)
	{
	    cout << arr[i]->getPer()<<endl;
		cout << arr[i]->getArea()<<endl;
	}


}



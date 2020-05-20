
using namespace std;
#include <fstream>
#include <vector>
#include "ShapeCollection.h"

int main()
{
	ShapeCollection sh;

	sh.AddCircle(3, 3, 5);
	sh.AddTriagnle(1, 4, 2, 11, 7, 4);
	sh.AddRect(1, 1, 4, 4);

	sh.PrintAllAreas();

/*  lamda fucntion example
	std::vector<Circle> s;
	s.push_back(Circle(3, 4, 4));
	s.push_back(Circle(1, 2, 3));

	std::sort(s.begin(), s.end(),
		[](Circle& lhs, Circle& rhs) -> bool
	{
		return lhs.getArea() < rhs.getArea();
	});*/



}
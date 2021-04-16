#include "UniCourse.h"

int main()
{
	UniCourse u("ddz");

	u.addStudent("ivan", 80123);
	u.addStudent("angel", 80125);
	u.addStudent("petur", 80126);
	u.addStudent("ivan2", 81000);
	//u.print();

	u.removeStudent(80125);
	u.print();
}
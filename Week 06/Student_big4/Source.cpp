#include <iostream>
#include "Student.h"
using namespace std;


int main()
{
	Student st;

	st.setName("Ivan");

	int grades[] = { 2,4,6 };
	int gradesCount = 3;

	st.setGrades(grades, gradesCount);
}
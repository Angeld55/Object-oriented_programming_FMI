#include <iostream>
#include "Student.h"
#include <utility>

using namespace std;


int main()
{
	Student st;

	st.setName("Ivan");

	int grades[] = { 2,4,6 };
	int gradesCount = 3;

	st.setGrades(grades, gradesCount);


	Student st2(std::move(st));
}
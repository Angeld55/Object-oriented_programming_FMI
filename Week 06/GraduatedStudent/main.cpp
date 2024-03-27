#pragma once
#include <iostream>
#include "GraduatedStudent.h"

int main()
{
	int grades[] = { 3,3,4,4,5,5 };
	GraduatedStudent gr("Test Student", grades, sizeof(grades) / sizeof(int), "Winning!");

	std::cout << gr.getName();
}
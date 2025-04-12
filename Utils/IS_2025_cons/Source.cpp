#include <iostream>
#include "SerializableString¿rray.h"
int main()
{
	SerializableString¿rray sa(10, 10);

	sa.addString("TEST");
	sa.addString("ddz");
	sa.addString("oop");

	for (int i = 0; i < sa.getSize(); i++)
		std::cout << sa.get(i) << std::endl;

	sa.writeToBinary("sa.dat");

	SerializableString¿rray newSa("sa.dat");
	for (int i = 0; i < newSa.getSize(); i++)
		std::cout << newSa.get(i) << std::endl;
	
}
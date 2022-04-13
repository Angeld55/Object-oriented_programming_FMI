#include<iostream>
#include"vector.h"

int main() {
	vector v;

	for (int i = 0; i < 100; i++)
		v.push_back(i);

	v[78] = 1000;

	for (int i = 0; i < 100; i++)
		std::cout << v[i] << " ";

	std::cout << std::endl << v.getSize();
}

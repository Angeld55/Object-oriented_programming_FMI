#pragma warning(disable: 4996)
#include "EnergyDrink.h"
#include <iostream>

EnergyDrink::EnergyDrink(const char* name, int ml, const char* sertificate) : Drink(name, ml), qualityCertificate(nullptr)
{
	setCertificate(sertificate);
}
const char* EnergyDrink::getCertifiate() const
{
	return qualityCertificate;
}
void EnergyDrink::setCertificate(const char* certficate)
{
	delete[] qualityCertificate;

	qualityCertificate = new char[strlen(certficate) + 1];
	strcpy(qualityCertificate, certficate);

}
EnergyDrink::EnergyDrink(const EnergyDrink& other) : Drink(other)
{
	copyFrom(other);
}

EnergyDrink& EnergyDrink::operator=(const EnergyDrink& other)
{
	if (this != &other)
	{
		Drink::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

EnergyDrink::~EnergyDrink()
{
	free();
}
void EnergyDrink::copyFrom(const EnergyDrink& other)
{
	qualityCertificate = new char[strlen(other.qualityCertificate) + 1];
	strcpy(qualityCertificate, other.qualityCertificate);
}
void EnergyDrink::free()
{
	delete[] qualityCertificate;
}
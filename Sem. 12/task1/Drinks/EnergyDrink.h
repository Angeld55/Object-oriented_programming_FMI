// име, мл, сертификат за качество.
#pragma once
#include "Drink.h"

class EnergyDrink : public Drink
{
private:
	char* qualityCertificate;

	void copyFrom(const EnergyDrink& other);
	void free();

public:
	EnergyDrink(const char* name, int ml, const char* certificate);
	
	EnergyDrink(const EnergyDrink& other);
	EnergyDrink& operator=(const EnergyDrink& other);
	~EnergyDrink();

	const char* getCertifiate() const;
	void setCertificate(const char* certificate);
};
#include "Airport.h"

Airport::Airport(const char* cityName,const char* id)
{
	this->cityName = new char[strlen(cityName) + 1];
	strcpy(this->cityName, cityName);

	strcpy(this->id, id);
}

void Airport::CopyFrom(const Airport& other)
{
	cityName = new char[strlen(other.cityName) + 1];
	strcpy(cityName, other.cityName);

	strcpy(id, other.id); //въпреки че не е динамично заделен, се налага до разпишем ръчно копирането, защото го разписваме за другите член-данни в класа. 
}

void Airport::Free()
{
	delete[] cityName;
}

Airport::Airport(const Airport& other)
{
	CopyFrom(other);
}

Airport& Airport::operator=(const Airport& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;

}

Airport::~Airport()
{
	Free();
}

const char* Airport::getId() const
{
	return id;
}
const char* Airport::getCityName() const
{
	return cityName;
}
void Airport::print() const
{
	std::cout << cityName << '(' << id << ')';
}

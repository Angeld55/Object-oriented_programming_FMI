#include "Airline.h"

int Airline::firstFreeIndex()
{
	for (int i = 0; i < MAXFLIGHTS; i++)
	{
		if (fl[i] == nullptr)
			return i;
	}
	return -1;
}
void Airline::CopyFrom(const Airline& other)
{
	name = new char[strlen(other.name) + 1]; //Копираме именето
	strcpy(name, other.name);

	for (int i = 0; i < MAXFLIGHTS; i++)
	{
		if (other.fl[i] == nullptr)
			fl[i] = nullptr;
		else
		{
			fl[i] = new Flight(*other.fl[i]); //извикваме копи контруктора на обектите.
		}					  // Понеже в other.fl[i] e указател, то трябва да го 'дерефрираме'.	
	}
}
void Airline::Free()  //трябва да изтрием името и всички обекти, към които сочат указателите
{
	delete[] name;
	for (int i = 0; i < MAXFLIGHTS; i++) 
		delete fl[i]; //някои указатели може да имат стойност nullptr, но това няма да доведе до грешка.
}


Airline::Airline(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	for (int i = 0; i < MAXFLIGHTS; i++)
		fl[i] = nullptr; 
}

bool Airline::addFlight(const char* originAirportName, const char* originAirportId,
	const char* destAirportName, const char* destAirportId, int durration)
{
	int ind = firstFreeIndex();

	if (ind == -1) //няма свободни места.
		return false;

	fl[ind] = new Flight(originAirportName, originAirportId, destAirportName, destAirportId, durration);
	return true;

}
bool Airline::addFlight(const Flight& other)
{
	int ind = firstFreeIndex();

	if (ind == -1)//няма свободни места.
		return false; 
	fl[ind] = new Flight(other);
	return true;
}
Airline::Airline(const Airline& other)
{
	CopyFrom(other);
}
Airline& Airline::operator=(const Airline& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Airline::~Airline()
{
	Free();
}
bool Airline::containsJourney(const char* originID, const char* destID)
{
	//TODO -> fix cycles
	if (strcmp(originID, destID))
		return true;
	
	bool solution = false;

	for (int i = 0; i < MAXFLIGHTS && !solution; i++)
	{
		if (fl[i] != nullptr)
		{
			if (strcmp(fl[i]->getOrigin().getId(), originID) == 0)
				solution = solution || containsJourney(fl[i]->getDestination().getId(), destID);
		}
	}
	return false;
}
void Airline::print()
{
	for (int i = 0; i < MAXFLIGHTS; i++)
	{
		if (fl[i])
		{
			std::cout << "Flight: ";
			fl[i]->print();
		}
	}
}

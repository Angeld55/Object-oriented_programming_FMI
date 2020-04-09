#include "Flight.h"

const int MAXFLIGHTS = 10;

class Airline
{
	char* name;
	Flight* fl[MAXFLIGHTS]; //масив от указатели към обекти от тип Flight.

	int firstFreeIndex();

	void CopyFrom(const Airline& other);
	void Free();

public:
	Airline(const char* name);
	Airline(const Airline& other);
	Airline& operator=(const Airline& other);
	~Airline();

	bool addFlight(const char* originAirportName, const char* originAirportId,
		const char* destAirportName, const char* destAirportId, int durration);
	bool addFlight(const Flight& other);

	bool containsJourney(const char* origin, const char* dest);

	void print();
};

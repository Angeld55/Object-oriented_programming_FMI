#include "Airport.h"

class Flight
{


	Airport origin;
	Airport dest;
	int durration;

public:
	Flight(const char* originAirportName, const char* originAirportId,
		const char* destAirportName, const char* destAirportId, int durration);

	Flight(const Airport& origin,const Airport& dest, int durration);

	const Airport& getOrigin();
	const Airport& getDestination();

	void print() const;
};
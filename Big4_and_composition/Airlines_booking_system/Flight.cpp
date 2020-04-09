#include "Flight.h"

Flight::Flight(const char* originAirportName, const char* originAirportId,
	const char* destAirportName, const char* destAirportId, int durration) : origin(originAirportName, originAirportId), dest(destAirportName,destAirportId)
{
	this->durration = durration;
}

Flight::Flight(const Airport& _origin, const Airport& _dest, int durration) : origin(_origin), dest(_dest)
{
	this->durration = durration;
}
const Airport& Flight::getOrigin()
{
	return origin;
}
const Airport& Flight::getDestination()
{
	return dest;
}
void Flight::print() const
{
	origin.print();
	std::cout << "-->";
	dest.print();
	std::cout << std::endl;
}
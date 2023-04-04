#include "Bus.h"

Bus::Bus():id(0), maxSeats(0), ticketsPriceAdults(0), ticketsPriceStudents(0), isFree(false) {}

Bus::Bus(unsigned id, unsigned maxSeats, unsigned ticketsPriceAdults, unsigned ticketsPriceStudents) :
	id(id), maxSeats(maxSeats), ticketsPriceAdults(ticketsPriceAdults),
	ticketsPriceStudents(ticketsPriceStudents), isFree(true) {}

unsigned Bus::getId() const
{
	return id;
}

unsigned Bus::getMaxSeats() const
{
	return maxSeats;
}

unsigned Bus::getTicketsPriceAdults() const
{
	return ticketsPriceAdults;
}

unsigned Bus::getTicketsPriceStudents() const
{
	return ticketsPriceStudents;
}

bool Bus::isBusFree() const
{
	return isFree;
}

void Bus::useBus()
{
	isFree = false;
}

void Bus::stopUsingBus()
{
	isFree = true;
}

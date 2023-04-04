#include "BusStation.h"

void BusStation::copyFrom(const BusStation& other)
{
	copyBusses(other.busses, other.bussesCount);
	copyTrips(other.trips, other.tripsCount, other.tripsCapacity);
}

void BusStation::copyBusses(const Bus* b, unsigned count)
{
	bussesCount = count;
	for (unsigned i = 0; i < bussesCount; i++)
	{
		busses[i] = b[i];
	}
}

void BusStation::copyTrips(const Trip* t, unsigned count, unsigned capacity)
{
	tripsCount = count;
	tripsCapacity = capacity;
	trips = new Trip[tripsCapacity];
	for (unsigned i = 0; i < count; i++)
	{
		trips[i] = t[i];
	}
}

void BusStation::free()
{
	delete[] trips;
	trips = nullptr;
	tripsCount = tripsCapacity = bussesCount = 0;
}

void BusStation::resize(unsigned newCapacity)
{
	tripsCapacity = newCapacity;
	Trip* temp = new Trip[tripsCapacity];

	for (unsigned i = 0; i < tripsCount; i++)
	{
		temp[i] = trips[i];
	}

	delete[] trips;
	trips = temp;
}

int BusStation::findTripWithDestination(const char* dest) const
{
	for (unsigned i = 0; i < tripsCount; i++)
	{
		if (strcmp(trips[i].getDestination(), dest) == 0 && !trips[i].isFull()
			&& trips[i].isTripUpcomming()) {
			return i;
		}
	}
	return -1;
}

int BusStation::findFreeBus() const
{
	for (unsigned i = 0; i < bussesCount; i++)
	{
		if (busses[i].isBusFree()) {
			return i;
		}
	}
	return -1;
}

int BusStation::findBusById(unsigned id) const
{
	for (unsigned i = 0; i < bussesCount; i++)
	{
		if (busses[i].getId() == id) {
			return i;
		}
	}
	return -1;
}

BusStation::BusStation()
{
	tripsCapacity = 8;
	trips = new Trip[tripsCapacity];
	tripsCount = bussesCount = 0;
}

BusStation::BusStation(const BusStation& other)
{
	copyFrom(other);
}

BusStation& BusStation::operator=(const BusStation& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

BusStation::~BusStation()
{
	free();
}

bool BusStation::doesPassengerHaveSeat(const char* name, const Trip& trip) const
{
	return trip.doesPassergerHaveSeat(name);
}

bool BusStation::addPassenger(const Passenger& passenger, const char* dest)
{
	int idx = findTripWithDestination(dest);
	if (idx == -1) {
		return false;
	}

	trips[idx].addPassenger(passenger);
	if (trips[idx].isFull()) {
		trips[idx].startTrip();
	}
	return true;
}

void BusStation::busArrives(unsigned id)
{
	int idx = findBusById(id);
	if (idx == -1) {
		return;
	}

	busses[idx].stopUsingBus();
}

bool BusStation::addBus(const Bus& bus)
{
	if (bussesCount == MAX_BUSSES_COUNT) {
		return false;
	}

	busses[bussesCount++] = bus;
	return true;
}

bool BusStation::addTrip(const char* dest)
{
	int idx = findFreeBus();
	if (idx == -1) {
		return false;
	}

	if (tripsCount == tripsCapacity) {
		resize(tripsCapacity * 2);
	}

	Trip trip(dest, &busses[idx]);
	trips[tripsCount++] = trip;
	return true;
}

unsigned BusStation::getTotalProfit() const
{
	unsigned sum = 0;
	for (unsigned i = 0; i < tripsCount; i++)
	{
		sum += trips[i].getPriceForTrip();
	}
	return sum;
}

void BusStation::printCurrentBusses() const
{
	for (unsigned i = 0; i < tripsCount; i++)
	{
		if (trips[i].isTripUpcomming()) {
			trips[i].printTrip();
		}
	}
}
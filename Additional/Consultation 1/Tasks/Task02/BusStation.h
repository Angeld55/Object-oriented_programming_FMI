#pragma once
#include "Bus.h"
#include "Trip.h"

const unsigned MAX_BUSSES_COUNT = 30;

class BusStation
{
	Bus busses[MAX_BUSSES_COUNT];
	unsigned bussesCount;
	Trip* trips;
	unsigned tripsCount;
	unsigned tripsCapacity;

	void copyFrom(const BusStation& other);
	void copyBusses(const Bus* b, unsigned count);
	void copyTrips(const Trip* t, unsigned count, unsigned capacity);
	void free();
	void resize(unsigned newCapacity);

	int findTripWithDestination(const char* dest) const;
	int findFreeBus() const;
	int findBusById(unsigned id) const;

public:
	BusStation();
	BusStation(const BusStation& other);
	BusStation& operator=(const BusStation& other);
	~BusStation();

	bool doesPassengerHaveSeat(const char* name, const Trip& trip) const;
	bool addPassenger(const Passenger& passenger, const char* dest);

	void busArrives(unsigned id);

	bool addBus(const Bus& bus);
	bool addTrip(const char* dest);

	unsigned getTotalProfit() const;
	void printCurrentBusses() const;
};
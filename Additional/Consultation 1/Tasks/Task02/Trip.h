
#pragma once
#include "Bus.h"
#include "Passenger.h"

class Trip
{
	char* destination;
	Bus* bus;
	Passenger* passengers;
	unsigned passengersCount;
	unsigned passengersCapacity;
	bool isUpcomming;

	void copyFrom(const Trip& other);
	void copyDest(const char* dest);
	void copyPassengers(const Passenger* pass, unsigned count, unsigned capacity);
	void free();

public:
	Trip();
	Trip(const char* destination, Bus* bus);
	Trip(const Trip& other);
	Trip& operator=(const Trip& other);
	~Trip();

	const Bus* getBus() const;
	const char* getDestination() const;

	void addPassenger(const Passenger& passenger);
	unsigned getPriceForTrip() const;
	unsigned getFreeSeats() const;

	bool doesPassergerHaveSeat(const char* name) const;
	void startTrip();
	bool isTripUpcomming() const;
	void printTrip() const;
	bool isFull() const;
};
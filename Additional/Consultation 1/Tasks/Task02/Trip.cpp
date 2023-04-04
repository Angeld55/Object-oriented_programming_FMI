#include "Trip.h"
#pragma warning (disable : 4996)

void Trip::copyFrom(const Trip& other)
{
	copyDest(other.destination);
	bus = other.bus;
	copyPassengers(other.passengers, other.passengersCount, other.passengersCapacity);
	isUpcomming = other.isUpcomming;
}

void Trip::copyDest(const char* dest)
{
	destination = new char[strlen(dest) + 1];
	strcpy(destination, dest);
}

void Trip::copyPassengers(const Passenger* pass, unsigned count, unsigned capacity)
{
	passengers = new Passenger[capacity];
	passengersCount = count;
	passengersCapacity = capacity;
	for (unsigned i = 0; i < passengersCount; i++)
	{
		passengers[i] = pass[i];
	}
}

void Trip::free()
{
	delete[] passengers;
	delete[] destination;
	passengers = nullptr;
	bus = nullptr;
	destination = nullptr;
	passengersCount = passengersCapacity = 0;
}

Trip::Trip() : bus(nullptr), passengers(nullptr), passengersCount(0), isUpcomming(false) {
	copyDest("Unknown");
}


Trip::Trip(const char* destination, Bus* bus)
{
	copyDest(destination);
	this->bus = bus;
	this->bus->useBus();
	passengers = new Passenger[bus->getMaxSeats()];
	passengersCount = 0;
	passengersCapacity = bus->getMaxSeats();
	isUpcomming = true;
}

Trip::Trip(const Trip& other)
{
	copyFrom(other);
}

Trip& Trip::operator=(const Trip& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Trip::~Trip()
{
	free();
}

const Bus* Trip::getBus() const
{
	return bus;
}

const char* Trip::getDestination() const
{
	return destination;
}

void Trip::addPassenger(const Passenger& passenger)
{
	if (passengersCount == passengersCapacity) {
		return;
	}

	passengers[passengersCount++] = passenger;
}

unsigned Trip::getPriceForTrip() const
{
	unsigned sum = 0;
	for (unsigned i = 0; i < passengersCount; i++)
	{
		if (passengers[i].isStudent()) {
			sum += bus->getTicketsPriceStudents();
		}
		else {
			sum += bus->getTicketsPriceAdults();
		}
	}
	return sum;
}

unsigned Trip::getFreeSeats() const
{
	return passengersCapacity - passengersCount;
}

bool Trip::doesPassergerHaveSeat(const char* name) const
{
	for (unsigned i = 0; i < passengersCount; i++)
	{
		if (strcmp(passengers[i].getName(), name) == 0) {
			return true;
		}
	}
	return false;
}

void Trip::startTrip()
{
	isUpcomming = false;
}

bool Trip::isTripUpcomming() const
{
	return isUpcomming;
}

void Trip::printTrip() const
{
	std::cout << "Bus N" << bus->getId() << " leaves for "
		<< destination << ". Free seats: " << passengersCapacity - passengersCount
		<< std::endl;
}

bool Trip::isFull() const
{
	return passengersCount == passengersCapacity;
}

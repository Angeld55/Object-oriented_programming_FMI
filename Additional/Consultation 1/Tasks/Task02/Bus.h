#pragma once

class Bus {
	unsigned id;
	unsigned maxSeats;
	unsigned ticketsPriceAdults;
	unsigned ticketsPriceStudents;
	bool isFree;

public:
	Bus();
	Bus(unsigned id, unsigned maxSeats,
		unsigned ticketsPriceAdults,
		unsigned ticketsPriceStudents);

	unsigned getId() const;
	unsigned getMaxSeats() const;
	unsigned getTicketsPriceAdults() const;
	unsigned getTicketsPriceStudents() const;

	bool isBusFree() const;
	void useBus();
	void stopUsingBus();
};
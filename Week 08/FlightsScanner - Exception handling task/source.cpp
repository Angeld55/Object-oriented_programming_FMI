#include <iostream>
#include "FlightScanner.h"

int main()
{
	FlightScanner scanner("inputFlights.txt", "outputFlights.txt", 10);

	scanner.run();
}
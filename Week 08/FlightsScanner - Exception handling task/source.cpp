#include <iostream>
#include "FlightsScanner.h"

int main()
{
	FlightsScanner scanner("inputFlights.txt", "outputFlights.txt", 10);
	scanner.run();
}
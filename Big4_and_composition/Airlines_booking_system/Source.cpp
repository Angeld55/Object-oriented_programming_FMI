
#include "Airline.h"



int main()
{

	Airline a("Lufthansa");
	a.addFlight("Sofia", "SOF", "Berlin", "TGL", 33);

	a.addFlight("Berlin", "TGL", "London", "LTN", 55);

	a.addFlight("London", "LTN", "Sofia", "SOF", 66);

	a.addFlight("Berlin", "SCH", "Sofia", "SOF", 51);

	a.addFlight("London", "LTN", "Moscow", "MSC", 96);

	a.print();
	

} 
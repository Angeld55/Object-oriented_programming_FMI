#include <iostream>
#include "BusStation.h"

int main()
{
    Passenger p1("Ivan", 17);
    Passenger p2("Georgi", 17);
    Passenger p3("Maria", 23);

    Bus b1(1, 2, 10, 5);
    Bus b2(2, 2, 10, 5);

    BusStation bs;
    bs.addBus(b1);
    bs.addBus(b2);

    std::cout << bs.addTrip("Kazanlak") << std::endl; //1
    std::cout << bs.addTrip("Burgas") << std::endl; //1
    std::cout << bs.addTrip("Burgas") << std::endl; //0

    bs.printCurrentBusses();

    std::cout << bs.addPassenger(p1, "Burgas") << std::endl; //1
    std::cout << bs.addPassenger(p2, "Burgas") << std::endl; //1
    std::cout << bs.addPassenger(p3, "Burgas") << std::endl; //0

    bs.busArrives(2);
    std::cout << bs.addTrip("Burgas") << std::endl; //1
    std::cout << bs.addPassenger(p3, "Burgas") << std::endl; //1

    bs.printCurrentBusses();
    std::cout << bs.getTotalProfit() << std::endl; //20
}

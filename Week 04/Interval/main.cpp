#include <iostream>
#include "EventCollection/EventCollection.h"
int main()
{
	EventCollection ev;
	
	ev.addEvent(Event("Party", 31, 12, 2023, 23, 0, 0, 23, 30, 00));
	ev.addEvent(Event("Sleep", 1, 1, 2024, 5, 0, 0, 11, 30, 00));


	std::cout << ev.getByIndex(1).getDate().getYear();

}

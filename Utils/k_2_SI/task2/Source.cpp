#include "EventManager/EventManager.h"
int main()
{
	EventManager em;

	em.addEventTypeA(10, 30, 12, 30, "ACS");
	em.addEventTypeB(11, 00, 12, 00, 13, 00);

	em.getDuration(0);
	em.getDuration(1);

	std::cout<< em.getEventsCountDuringTime(12, 20);

	em.getType(1);
}
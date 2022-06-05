#include "EventManager.h"

#include "../Event/EventTypeA.h"
#include "../Event/EventTypeB.h"
#include "../Event/EventTypeC.h"
#include <exception>

void EventManager::free()
{
	for (size_t i = 0; i < eventsCount; i++)
		delete events[i];  //не се инт. какъв обект е. (вирт дестр)
	delete[] events;
}
void EventManager::copyFrom(const EventManager& other)
{
	events = new Event * [other.eventsCount];
	eventsCount = other.eventsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < eventsCount; i++)
	{
		events[i] = other.events[i]->clone();
	}
}

void EventManager::resize()
{
	Event** newCollection = new Event * [capacity *= 2];
	for (size_t i = 0; i < eventsCount; i++)
		newCollection[i] = events[i]; // !!не правим клониране
	delete[] events;
	events = newCollection;
}

EventManager::EventManager()
{
	capacity = 8;
	eventsCount = 0;
	events = new Event * [capacity];
}

EventManager::EventManager(const EventManager& other)
{
	copyFrom(other);
}
EventManager& EventManager::operator=(const EventManager& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
EventManager::~EventManager()
{
	free();
}

void EventManager::addEvent(Event* event)
{
	if (eventsCount == capacity)
		resize();
	events[eventsCount++] = event; //we dont make a copy here (it's a private function, called from creation funcions)
}

//By including the Eventmanager we DONT include the 3 diffrent classes.
//Since the user DOES NOT KNOW about the 3 diffrent classes (A,B,C) the validation can be done here!

void EventManager::addEventTypeA(size_t startH, size_t startM, size_t endH, size_t endM, const char* name)
{
	//validation 

	addEvent(new EventTypeA(startH, startM, endH, endM, name));
}
void EventManager::addEventTypeB(size_t startH, size_t startM, size_t breakH, size_t breakM, size_t endH, size_t endM)
{
	//validation 

	addEvent(new EventTypeB(startH, startM, endH, endM, breakH, breakM));
}
void EventManager::addEventTypeC(size_t startH, size_t startM, size_t break1H, size_t break1M, size_t break2H, size_t break2M, size_t endH, size_t endM)
{
	//validation
	addEvent(new EventTypeC(startH, startM, endH, endM, break1H, break1M, break2H, break2M));

}
Time EventManager::getDuration(size_t ind) const
{
	if (ind >= eventsCount)
		throw std::out_of_range("Out of range");
	return events[ind]->getLength();
}
size_t EventManager::getEventsCountDuringTime(size_t hours, size_t mins)
{
	Time t(hours, mins);
	size_t count = 0;
	for (size_t i = 0; i < eventsCount; i++)
	{
		if (events[i]->duringTime(t))
			count++;
	}
	return count;
}
Event::EventType EventManager::getType(size_t ind) const
{
	if (ind >= eventsCount)
		throw std::out_of_range("Out of range");
	return events[ind]->getType();
}
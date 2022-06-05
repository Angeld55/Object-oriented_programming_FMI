#include "EventTypeA.h"
#include <cstring>

void EventTypeA::copyFrom(const EventTypeA& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void EventTypeA::free()
{
	delete[] name;
}

EventTypeA::EventTypeA(size_t startH, size_t startM, size_t endH, size_t endM, const char* name) : Event(type, startH, startM, endH, endM)
{
	setName(name);
}

EventTypeA::EventTypeA(const EventTypeA& other) : Event(other)
{
	copyFrom(other);
}
EventTypeA& EventTypeA::operator=(const EventTypeA& other)
{
	if (this != &other)
	{
		Event::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}
EventTypeA::~EventTypeA()
{
	free();
}

void EventTypeA::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

bool EventTypeA::duringTime(const Time& time) const
{
	return (start <= time) && (time <= end);
}
Time EventTypeA::getLength() const
{
	return end - start;
}

Event* EventTypeA::clone() const
{
	return new EventTypeA(*this);
}

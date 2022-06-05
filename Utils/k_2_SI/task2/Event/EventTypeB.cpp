#include "EventTypeB.h"

EventTypeB::EventTypeB(size_t startH, size_t startM, size_t endH, size_t endM, size_t break1H, size_t break1M) : Event(type, startH, startM, endH, endM), break1(break1H, break1M)
{}

bool EventTypeB::duringTime(const Time& time) const
{
	return (start <= time && time <= break1)             || 
		   (break1 + Time(0, 5) <= time && time <= end); 
}
Time EventTypeB::getLength() const
{
	return break1 - start + (end - (break1 + Time(0, 5))); //the 5 mins break
}

Event* EventTypeB::clone() const
{
	return new EventTypeB(*this);
}

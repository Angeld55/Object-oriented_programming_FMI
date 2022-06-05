#include "EventTypeC.h"

EventTypeC::EventTypeC(size_t startH, size_t startM, size_t endH, size_t endM, size_t break1H, size_t break1M, size_t break2H, size_t break2M) : Event(type, startH, startM, endH, endM), break1(break1H, break1M), break2(break2H, break2M)
{}

bool EventTypeC::duringTime(const Time& time) const
{
	return  start <= time && time <= break1               ||
			break1 + Time(0, 5) <= time && time <= break2 ||
			break2 + Time(0, 5) <= time && time <= end;
}

Time EventTypeC::getLength() const
{
	return break1 - start + (break2 - (break1 + Time(0, 5))) //first break
			+ end - (break2 + Time(0, 5)); //second break
}

Event* EventTypeC::clone() const
{
	return new EventTypeC(*this);
}

#include "EventCollection.h"

bool EventCollection::addEvent(const Event& event)
{
	if (count == 20)
		return false;
	data[count++] = event; // копие!!!
	return true;
}

void EventCollection::remove(unsigned ind)
{
	if (ind >= count)
		return;
	std::swap(data[ind], data[count - 1]);
	count--;
}

const Event& EventCollection::getByIndex(unsigned ind)
{
	if (ind >= count)
		throw "Error";
	return data[ind];
}

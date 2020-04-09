#include "Schedule.h"

int Schedule::getFirstFreeSlotIndex()
{
	for (int i = 0; i < MAXEVENTS; i++)
	{
		if (!events[i].getIsInit())
			return i;
	}
	return -1;
}
void Schedule::DeleteEvent(int ind)
{
	Event emptyEvent;
	events[ind] = emptyEvent;
}

bool Schedule::AddEvent(const char* name, int startHours, int startMin, int startSec, int endHours, int endMin, int endSec)
{
	int freeIndex = getFirstFreeSlotIndex();
	if (freeIndex == -1)
		return false;
	Event eventToAdd(name, startHours, startMin, startSec, endHours, endMin, endSec);
	events[freeIndex] = eventToAdd;

	return true;
}
bool Schedule::RemoveEvent(const char* name)
{
	for (int i = 0; i < MAXEVENTS; i++)
	{
		if (strcmp(events[i].getName(), name) == 0)
		{
			DeleteEvent(i);
			return true;
		}
	}
	return false;
}
bool Schedule::RemoveEvent(int startHours, int startMin, int startSec, int endHours, int endMin, int endSec)
{
	Time startToRemove(startHours, startMin, startSec);
	Time endToRemove(endHours, endMin, endSec);

	for (int i = 0; i < MAXEVENTS; i++)
	{
		if ((events[i].getStart().CompareTo(startToRemove)) == 0 && (events[i].getEnd().CompareTo(endToRemove) == 0))
		{
			DeleteEvent(i);
			return true;
		}
	}
	return false;
}
void Schedule::Print() const
{
	for (int i = 0; i < MAXEVENTS; i++)
	{
		if (events[i].getIsInit())
			events[i].print();
	}
}
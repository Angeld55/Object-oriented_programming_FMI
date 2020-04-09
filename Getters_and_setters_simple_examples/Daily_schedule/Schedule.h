#include "Event.h"

const int MAXEVENTS = 10;
class Schedule
{
private:
	Event events[MAXEVENTS];

	int getFirstFreeSlotIndex();
	void DeleteEvent(int ind);


public:
	bool AddEvent(const char* name, int startHours, int startMin, int startSec, int endHours, int endMin, int endSec);
	bool RemoveEvent(const char* name);
	bool RemoveEvent(int startHours, int startMin, int startSec, int endHours, int endMin, int endSec);
	void Print() const;
	bool isValidSchedule() const;
};

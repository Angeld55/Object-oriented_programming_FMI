#include "Time.h"

class Event
{
	char name[30];
	Time start;
	Time end;
	bool isInit;
public:
	Event();
	Event(const char* name, int startHours, int startMin, int startSec, int endHours, int endMin, int endSec);
	bool IsValid();
	void print() const;
	const Time& getStart() const;
	const Time& getEnd() const;
	const char* getName() const;
	bool getIsInit() const;
};


#include "Event.h"

class EventTypeB : public Event
{
	Time break1;

public:

	EventTypeB(size_t startH, size_t startM, size_t endH, size_t endM, size_t breakH, size_t breakM);


	bool duringTime(const Time& time) const override;
	Time getLength() const override;
	Event* clone() const override;

};
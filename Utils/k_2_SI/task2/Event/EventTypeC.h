#include "Event.h"

class EventTypeC : public Event
{
	Time break1;
	Time break2;

public:

	EventTypeC(size_t startH, size_t startM, size_t endH, size_t endM, size_t break1H, size_t break1M, size_t break2H, size_t break2M);

	bool duringTime(const Time& time) const override;
	Time getLength() const override;
	Event* clone() const override;
};
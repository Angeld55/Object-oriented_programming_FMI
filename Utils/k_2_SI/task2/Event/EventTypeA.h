#include "Event.h"

class EventTypeA : public Event
{
	char* name = nullptr;

	void copyFrom(const EventTypeA& other);
	void free();
public:
	
	EventTypeA(size_t startH, size_t startM, size_t endH, size_t endM, const char* name);

	EventTypeA(const EventTypeA& other);
	EventTypeA& operator=(const EventTypeA& other);
	~EventTypeA();

	void setName(const char* name);


	bool duringTime(const Time& time) const override;
	Time getLength() const override;
	Event* clone() const override;

};
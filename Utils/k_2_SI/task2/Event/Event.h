#pragma once
#include "../Time/Time.h"
class Event
{

public:
	enum class EventType
	{
		typeA,
		typeB,
		typeC
	};

protected:
	Time start;
	Time end;

	EventType type;
public:


	Event(EventType type, size_t sHours, size_t sMins, size_t eHours, size_t eMins) : type(type), start(sHours, sMins), end(eHours, eMins){}
	virtual ~Event() = default;

	virtual bool duringTime(const Time& time) const = 0;
	virtual Time getLength() const = 0;
	virtual Event* clone() const = 0;

	EventType getType() const { return type; }
};
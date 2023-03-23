#pragma once
#include "../Event/Event.h"

class EventCollection
{
	Event data[20];
	unsigned count = 0; // 0 ... count - 1 са валидни обекти  count ... 19 са деф. стойности

public:
	EventCollection() = default;
	bool addEvent(const Event& event);
	void remove(unsigned ind);
	const Event& getByIndex(unsigned ind);
};
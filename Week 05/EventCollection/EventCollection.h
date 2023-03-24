#pragma once
#include "../Event/Event.h"

class EventCollection
{
	Event data[20];
	unsigned count = 0; // 0 ... count - 1 са добавени. От count до 19 са обекти създадени с default-на стойност,

public:
	EventCollection() = default;
	bool addEvent(const Event& event);
	void remove(unsigned ind);
	const Event& getByIndex(unsigned ind) const;
};

#include "../Event/Event.h"
#include <iostream>
class EventManager
{
	Event** events;

	void free();
	void copyFrom(const EventManager& other);
	void resize();

	void addEvent(Event* event);

	size_t eventsCount;
	size_t capacity;

public:
	EventManager();
	EventManager(const EventManager& other);
	EventManager& operator=(const EventManager& other);
	~EventManager();


	void addEventTypeA(size_t startH, size_t startM, size_t endH, size_t endM, const char* name);
	void addEventTypeB(size_t startH, size_t startM, size_t breakH, size_t breakM, size_t endH, size_t endM);
	void addEventTypeC(size_t startH, size_t startM, size_t break1H, size_t break1M, size_t break2H, size_t break2M, size_t endH, size_t endM);

	Time getDuration(size_t ind) const;
	size_t getEventsCountDuringTime(size_t hours, size_t mins);
	Event::EventType getType(size_t ind) const;
};
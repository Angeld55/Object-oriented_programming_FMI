#include "Event.h"


Event::Event() :start(0, 0, 0), end(0, 0, 0), isInit(false)
{ }
Event::Event(const char* name, int startHours, int startMin, int startSec, int endHours, int endMin, int endSec) : start(startHours, startMin, startSec), end(endHours, endMin, endSec)
{
	if (!IsValid())
		end = start;
	strcpy(this->name, name);

}
void Event::print() const
{
	std::cout << name << std::endl;
	std::cout << "start: ";
	start.print();
	std::cout << "end: ";
	end.print();
}
const Time& Event::getStart() const
{
	return start;
}
const Time& Event::getEnd() const
{
	return end;
}
const char* Event::getName() const
{
	return name;
}
bool Event::getIsInit() const
{
	return isInit;
}
bool Event::IsValid()
{
	return start.CompareTo( end) >= 0;
}
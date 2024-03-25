#include "Event/Event.h"

int main()
{
	Event e("Party", 31, 12, 2023, 23, 0, 0, 23, 30, 00);

	std::cout << e.getName();
}
#include<iostream>
#include"Time.h"

int main()
{
	//EXAMPLE:
	Time t(12, 40, 55);
	t.print(std::cout); //12:40:55

	t.addSeconds(5);
	t.print(std::cout); // 12:41:00

	t.addMinutes(4);
	t.print(std::cout); // 12:45:00

	t.addHours(1);
	t.print(std::cout); // 13:45:00

	Time now(2, 47, 26);

	std::cout << now.compareTo(t) << std::endl; //-1
	std::cout << now.isItTimeForParty() << std::endl; //1
	std::cout << now.isItTimeForDinner() << std::endl; //0

	Time diff = t.diff(now);
	diff.print(std::cout); //10:57:34
}
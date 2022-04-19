#include <iostream>

#include "StringPool.h"

int main()
{
	StringPool dict;
	((dict *= "Ivan") *= "Petur") *= "Alex";
	std::cout << dict << std::endl; // {Alex, Ivan, Petur}
	std::cout << dict["Alex"] << " " << dict["abc"] << std::endl; // 1 0

	StringPool dict2;
	((dict2 *= "Zebra") *= "Alex");

	StringPool result = dict + dict2;
	std::cout << result << std::endl; // {Alex, Ivan, Petur, Zebra}

	StringPool result2 = dict - dict2;
	std::cout << result2 << std::endl; // {Ivan, Petur}

	"NewWOrd" >> result2;
	result2 /= "NonExistingWord";
		std::cout << result2 << std::endl;  //{Ivan, NewWOrd, Petur}
	"Job" >> result2; 
	std::cout << result2 << std::endl;  //{Ivan, Job, NewWOrd, Petur}


}
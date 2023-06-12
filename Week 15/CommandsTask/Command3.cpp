#include "Command3.h"

Command3::Command3(int a, int b, int c)
{
	max = a >= b && a >= c ? a : b >= c ? b : c;
	min = a <= b && a <= c ? a : b <= c ? b : c;
	mid = a + b + c - max - min;
}
void Command3::execute(std::ostream& os)
{
	os << max << " " << mid << " " << min << std::endl;
}
#include <iostream>
#include <assert.h>
#include "GpsPath.h"


int main()
{
	GPSPath p;

	p.addPoint(1, 2);
	p.addPoint(1, 4);
	p.addPoint(1, 10);
	p.setPoint(1, 12, 1);

	std::cout << p.getDist();

}

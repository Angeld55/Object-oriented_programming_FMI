#include "Distance.h"

Distance::Distance()
{
	setCm(minCM);
	setM(minM);
	setKm(minKm);

}
Distance::Distance(int km, int m, int cm)
{
	setCm(cm);
	setM(m);
	setKm(km);
}
//constructs the distance by only given cm.
Distance::Distance(int cm)
{
	int km = cm / 100000;
	int rest = cm % 100000;
	int m = rest / 100;
	rest = rest % 100;

	setKm(km);
	setM(m);
	setCm(rest);


}
void Distance::setCm(int cm)
{
	if (cm < minCM || cm > maxCM)
		cm = minCM;
	this->cm = cm;
}
void Distance::setM(int m)
{
	if (m < minM || m > maxM)
		m = minM;
	this->m = m;
}
void Distance::setKm(int km)
{
	if (km < minKm)
		km = 0;
	this->km = km;
}
int Distance::getCm()const
{
	return cm;
}
int Distance::getM() const
{
	return m;
}
int Distance::getKm() const
{
	return km;
}
void Distance::Print() const
{
	std::cout << "KM:  " << km << " M:  " << m << " CM: " << cm << std::endl;
}
int Compare(const Distance& d1, const Distance& d2)
{
	if (d1.getKm() < d2.getKm())
		return -1;
	else if (d1.getKm() > d2.getKm())
		return 1;
	else
	{
		if (d1.getM() < d2.getM())
			return -1;
		else if (d1.getM() > d2.getM())
			return 1;
		else
		{
			if (d1.getCm() < d2.getCm())
				return -1;
			else if (d1.getCm() > d2.getCm())
				return 1;
			else
				return 0;
		}
	}
}
// if its between 66km and 99,5 km
bool Distance::isGreedy() const
{
	Distance lowLimit(66, 0, 0);
	Distance upLimit(99, 500, 0);
	return Compare(*this, lowLimit) > 0 && Compare(*this, upLimit) < 0;
}
int Distance::convertToCm() const
{
	return cm + m * 100 + km * 100000;
}
Distance getDiff(const Distance& d1, const Distance& d2)
{
	int cm1 = d1.convertToCm();
	int cm2 = d2.convertToCm();
	int diff = abs(cm1 - cm2);
	Distance result(diff);
	return result;
}

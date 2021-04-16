#include "TwoDimCoordSystem.h"

TwoDimCoordSystem::TwoDimCoordSystem(const Nvector& v1, const Nvector& v2) : v1(v1), v2(v2)
{
	if (~v1 != 2 || ~v2 != 2)
		throw "Size of vectors should be 2!";
	if (v1 || v2)
		throw "Vectors should not be parallel!";
}

Nvector TwoDimCoordSystem::getVectorByCoordinates(size_t coordX, size_t coordY) const
{
	//todo
}
Nvector TwoDimCoordSystem::getCoordinatesByVector(const Nvector& other) const
{
	//todo
}
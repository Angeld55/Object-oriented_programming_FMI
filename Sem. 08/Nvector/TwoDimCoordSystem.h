#include "Nvector.h"
class TwoDimCoordSystem
{
	Nvector v1;
	Nvector v2;

	TwoDimCoordSystem(const Nvector& v1, const Nvector& rhs);

	Nvector getVectorByCoordinates(size_t coordX, size_t coordY) const;
	Nvector getCoordinatesByVector(const Nvector& other) const;
};
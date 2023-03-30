#include "GpsPath.h"
#include <iostream>
#include <assert.h>

void GPSPath::copyFrom(const GPSPath& other) //приемаме, че няма данни в текущия обект
{
    count = other.count;
    capacity = other.capacity;
    data = new Point[capacity];
    currentPathLength = other.currentPathLength;
    for (unsigned i = 0; i < count; i++)
        data[i] = other.data[i];

}
void GPSPath::free()
{
    delete[] data;
    data = nullptr;
    count = capacity = 0;
}

GPSPath::GPSPath(const GPSPath& other)
{
    copyFrom(other);
}
GPSPath& GPSPath::operator=(const GPSPath& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
GPSPath::~GPSPath()
{
    free();
}

GPSPath::GPSPath()
{
    capacity = 8;
    data = new GPSPath::Point[capacity];
    count = 0;
    currentPathLength = 0;
}

void GPSPath::addPoint(int x, int y)
{
    if (count == capacity)
        resize(capacity * 2);
    Point newPoint{ x, y };
    data[count++] = newPoint; //point.operator=
    if (count > 1)
        currentPathLength += data[count - 2].getDist(data[count - 1]);
}

void GPSPath::resize(size_t newCapacity)
{
    Point* newData = new Point[newCapacity];
    for (unsigned i = 0; i < count; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;

}

void GPSPath::setPoint(int x, int y, unsigned ind)
{
    if (ind >= count)
        return;

    const Point& currentPoint = data[ind];

    Point newPoint{ x, y };
    if (ind == 0)
    {
        const Point& nextPoint = data[ind + 1];
        double dist = currentPoint.getDist(nextPoint);

        (currentPathLength -= dist) += newPoint.getDist(nextPoint);
    }
    else if (ind == count - 1)
    {
        const Point& prevPoint = data[ind - 1];
        double dist = currentPoint.getDist(prevPoint);

        (currentPathLength -= dist) += newPoint.getDist(prevPoint);

    }
    else
    {

        const Point& prevPoint = data[ind - 1];
        double dist1 = currentPoint.getDist(prevPoint);

        const Point& nextPoint = data[ind + 1];
        double dist2 = currentPoint.getDist(nextPoint);

        (currentPathLength -= dist1) -= dist2;

        currentPathLength += (newPoint.getDist(prevPoint) + newPoint.getDist(nextPoint));
    }

    data[ind] = newPoint;

}

double GPSPath::getDist() const
{
    return currentPathLength;
}
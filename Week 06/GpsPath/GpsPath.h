#pragma once
#include <cmath>
class GPSPath
{
    struct Point
    {
        int x;
        int y;
        double getDist(const Point& other) const
        {
            int dx = x - other.x;
            int dy = y - other.y;
            return sqrt(dx * dx + dy * dy);
        }
    };
    Point* data;
    size_t capacity;
    size_t count;
    double currentPathLength;

    void resize(size_t newCapacity);

    void copyFrom(const GPSPath& other);
    void free();
public:
    GPSPath();

    GPSPath(const GPSPath&);
    GPSPath& operator=(const GPSPath& other);
    ~GPSPath();

    void addPoint(int x, int y);
    double getDist() const;

    void setPoint(int x, int y, unsigned ind);

};
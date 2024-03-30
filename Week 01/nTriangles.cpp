#include <iostream>

namespace Points
{
    struct Point
    {
        int x = 0;
        int y = 0;
    };

    void readPoint(Point& point)
    {
        std::cin >> point.x;
        std::cin >> point.y;
    }

    double getDist(const Point& p1, const Point& p2)
    {
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;

        return sqrt(dx * dx + dy * dy);
    }

    void printPoint(const Point& point)
    {
        std::cout << "( " << point.x << " " << point.y << ") ";
    }
}

namespace Figures
{
    using namespace Points;
    struct Triangle
    {
        Point p1;
        Point p2;
        Point p3;
    };


    void readTriangle(Triangle& triangle)
    {
        readPoint(triangle.p1);
        readPoint(triangle.p2);
        readPoint(triangle.p3);
    }


    double getArea(const Triangle& triangle)
    {
        double sideA = getDist(triangle.p1, triangle.p2);
        double sideB = getDist(triangle.p2, triangle.p3);
        double sideC = getDist(triangle.p1, triangle.p3);

        double halfPer = (sideA + sideB + sideC) / 2;

        return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
    }

    void sortTrianglesByArea(Triangle* triangles, size_t N)
    {
        double* areas = new double[N];
        for (int i = 0; i < N; i++)
            areas[i] = getArea(triangles[i]);

        for (int i = 0; i < N - 1; i++)
        {
            int minAreaTriangleIndex = i;

            for (int j = i + 1; j < N; j++)
            {
                if (areas[j] < areas[minAreaTriangleIndex])
                    minAreaTriangleIndex = j;
            }

            if (minAreaTriangleIndex != i)
            {
                std::swap(triangles[i], triangles[minAreaTriangleIndex]);
                std::swap(areas[i], areas[minAreaTriangleIndex]);
            }
        }
        delete[] areas;
    }

    void printTriangle(const Triangle& triangle)
    {
        printPoint(triangle.p1);
        printPoint(triangle.p2);
        printPoint(triangle.p3);
        std::cout << std::endl;
    }
}
int main() 
{
    size_t N;
    std::cin >> N;

    Figures::Triangle* triangleArr = new Figures::Triangle[N];

    for (size_t i = 0; i < N; i++)
        Figures::readTriangle(triangleArr[i]);

    Figures::sortTrianglesByArea(triangleArr, N);

    for (size_t i = 0; i < N; i++)
        Figures::printTriangle(triangleArr[i]);

    delete[] triangleArr;
}

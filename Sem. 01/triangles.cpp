#include <iostream>
#include <cmath>

struct Point
{
	int x;
	int y;
};

void readPoint(Point& p)
{
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
	std::cout << p.x << " " << p.y;
}

double getDist(const Point& p1, const Point& p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return sqrt(dx*dx + dy*dy);
}

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
};

void readTriangle(Triangle& tr)
{
	readPoint(tr.p1);
	readPoint(tr.p2);
	readPoint(tr.p3);
}

void printTriangle(const Triangle& tr)
{
	printPoint(tr.p1);
	std::cout << " ";
	printPoint(tr.p2);
	std::cout << " ";
	printPoint(tr.p3);
	std::cout << std::endl;
}

double getArea(const Triangle& tr)
{
	double sideA = getDist(tr.p1, tr.p2);
	double sideB = getDist(tr.p2, tr.p3);
	double sideC = getDist(tr.p3, tr.p1);

	double halfPer = (sideA + sideB + sideC) / 2;

	return sqrt(halfPer*(halfPer - sideA)*(halfPer - sideB)*(halfPer - sideC));
}

void swap(double& a, double& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(Triangle& tr1, Triangle& tr2)
{
	Triangle temp = tr1;
	tr1 = tr2;
	tr2 = temp;
}

void selectionSort(double* areas,  Triangle* triangles, unsigned size)
{
	for (unsigned i = 0; i < size - 1; i++)
	{
		//findMin
		int minElementIndex = i;
		for (unsigned j = i + 1; j < size; j++)
		{
			if (areas[j] < areas[minElementIndex])
				minElementIndex = j;
		}
		if (minElementIndex != i)
		{
			swap(areas[i], areas[minElementIndex]);
			swap(triangles[i], triangles[minElementIndex]);
		}
	}
}

double* calculateAreas(const Triangle* arr, int n)
{
	double* areas = new double[n];

	for (int i = 0; i < n; i++)
		areas[i] = getArea(arr[i]);

	return areas;
}

int main()
{
	int n;
	std::cin >> n;

	Triangle* triangles = new Triangle[n];
	
	for (int i = 0; i < n; i++)
		readTriangle(triangles[i]);

	double* areas = calculateAreas(triangles,n);

	selectionSort(areas, triangles, n);

	for (int i = 0; i < n; i++)
		printTriangle(triangles[i]);

	delete[] triangles, areas;

}

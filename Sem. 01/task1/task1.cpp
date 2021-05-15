#include <iostream>
#include <chrono>

using namespace std;


struct point
{
	int x;
	int y;
};
void print(const point& ptr)
{
	cout << ptr.x << " " << ptr.y << endl;
}
point readPoint()
{
	int x, y;
	cin >> x >> y;
	return{ x, y };
}
double getDist(const point& origin, const point& dest)
{
	double dx = origin.x - dest.x;
	double dy = origin.y - dest.y;

	return sqrt(dx*dx + dy*dy);
}


struct triangle
{
	point p1;
	point p2;
	point p3;
};

double getArea(const triangle& tr)
{
	double sideA = getDist(tr.p1, tr.p2);
	double sideB = getDist(tr.p2, tr.p3);
	double sideC = getDist(tr.p3, tr.p1);

	double halfP = (sideA + sideB + sideC) / 2;
	return sqrt(halfP * (halfP - sideA) * (halfP - sideB) * (halfP - sideC));

}

void print(const triangle& tr)
{
	cout << "Point1: ";
	print(tr.p1);
	cout << "Point2: ";
	print(tr.p2);
	cout << "Point3: ";
	print(tr.p3);
	cout << getArea(tr) << endl << endl;
}

void swap(int * arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void swap(triangle* arr, int i, int j)
{
	triangle temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void selectionSort(int* areas, triangle* triangles, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int currPos = i;
		int min = i;

		for (int j = i; j < len; j++)
		{
			if (areas[j] < areas[min])
				min = j;
		}

		if (min != i)
		{
			swap(areas, i, min);
			swap(triangles, i, min);
		}
	}
}
int main()
{


	int n;
	cin >> n;
	
	triangle* triangles = new triangle[n];

	for (int i = 0; i < n; i++)
	{
		point p1 = readPoint();
		point p2 = readPoint();
		point p3 = readPoint();

		triangles[i].p1 = p1;
		triangles[i].p2 = p2;
		triangles[i].p3 = p3;
 	}

	int* areas = new int[n];


	for (int i = 0; i < n; i++)
		areas[i] = getArea(triangles[i]); 
	
	selectionSort(areas, triangles, n);

	for (int i = 0; i < n; i++)
		print(triangles[i]);

	delete[] triangles;
	delete[] areas;

}

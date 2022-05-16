#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;
    Point() : Point(0,0){}
    
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    double getDistance(const Point& other) const
    {
        int dx = x - other.x;
        int dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

void print(const Point& p)
{
    std::cout << "[ x: " << p.x << ", y: " << p.y <<" ]";
}

struct Rectangle
{
private:
    Point points[4];
    
public:
    Rectangle() = default; //the same as Rectangle() {}

    void setPoint(size_t index, int x, int y)
    {
        if(index > 3)
            return;
            
        points[index].x = x;
        points[index].y = y;

    }
    const Point& getPoint(size_t index) const
    {
        if(index > 3)
            return {}; //some Error. This is a refference to a temporary memory, so a better solution would be to throw an exception.
        return points[index];
    }
    double getPer() const
    {
        return 2 * points[0].getDistance(points[1]) + 2 * points[1].getDistance(points[2]);
    }
};

void print(const Rectangle& rect)
{
    for(int i = 0; i < 4; i++)
    {
        print(rect.getPoint(i));
    }
}

void swap(Rectangle& tr1, Rectangle& tr2)
{
	Rectangle temp = tr1;
	tr1 = tr2;
	tr2 = temp;
}

void selectionSort(Rectangle* triangles, double* perimeters, unsigned size)
{
	for (unsigned i = 0; i < size - 1; i++)
	{
		//findMin
		int minElementIndex = i;
		for (unsigned j = i + 1; j < size; j++)
		{
			if (perimeters[j] < perimeters[minElementIndex])
				minElementIndex = j;
		}
		
		if (minElementIndex != i)
		{
			swap(perimeters[i], perimeters[minElementIndex]);
			swap(triangles[i], triangles[minElementIndex]);
		}
	}
}

int main()
{
    ifstream file("rects.txt");
    
    if(!file.is_open())
    {
        std::cout << "Error while opening the file!";
        return -1;
    }

    int n;
    file >> n;
        
    Rectangle* rects = new Rectangle[n];
    double* perimeters = new double[n]; //this should be size_t, but we are using a double returning function for getDist.
    
    for(size_t i = 0; i < n; i++)
    {
        int x1, y1, x3, y3;
        file >> x1 >> y1 >> x3 >> y3;
        
        rects[i].setPoint(0, x1, y1);
        rects[i].setPoint(1, x1, y3);
        rects[i].setPoint(2, x3, y3);
        rects[i].setPoint(3, x3, y1);
        
        perimeters[i] = rects[i].getPer();

    }
    
    selectionSort(rects, perimeters, n); //selection sort, because we want min number of copies (or swaps)
    
    for(size_t i = 0; i < n; i++)
    {
        print(rects[i]);
        std::cout <<", Per: " << perimeters[i] << std::endl;
    }
    
    
    delete[] rects, perimeters;
    return 0;
}


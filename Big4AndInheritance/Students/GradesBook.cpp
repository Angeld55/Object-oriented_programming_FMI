#include "GradesBook.h"


GradesBook::GradesBook()
{
	capacity = 4;
	grades = new int[capacity];
	size = 0;
}
GradesBook::GradesBook(const GradesBook& other)
{
	std::cout << "Copy contr of GradesBook" << std::endl;
	CopyFrom(other);
}
GradesBook& GradesBook::operator=(const GradesBook& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
GradesBook::~GradesBook()
{
	Free();
}


void GradesBook::CopyFrom(const GradesBook& other)
{
	grades = new int[other.capacity];
	for (int i = 0; i < other.size; i++)
		grades[i] = other.grades[i];
	capacity = other.capacity;
	size = other.size;
}
void GradesBook::Free()
{
	delete[] grades;
}


bool GradesBook::isFull()
{
	return size == capacity;
}
void GradesBook::AddGrade(int grade)
{
	if (!isValidGrade(grade))
		return;
	if (isFull())
		Resize();
	grades[size++] = grade;

}
void GradesBook::Resize()
{
	int* temp = new int[capacity * 2];
	for (int i = 0; i < size; i++)
		temp[i] = grades[i];
	capacity *= 2;
	delete[] grades;
	grades = temp;
}
void GradesBook::RemoveLastGrade()
{
	size--;
}
bool GradesBook::isValidGrade(int grade)
{
	return (grade >= 2 && grade <= 6);
}
int GradesBook::operator[](int index) const
{
	if (index < 0 || index >= size)
		return -1;
	return grades[index];
}

std::ostream& operator<<(std::ostream& stream, GradesBook& obj)
{
	for (int i = 0; i < obj.capacity; i++)
	{
		if (i < obj.size)
			stream << obj.grades[i] << ' ';
		else
			stream << '_' << ' ';
	}
	return stream;
}
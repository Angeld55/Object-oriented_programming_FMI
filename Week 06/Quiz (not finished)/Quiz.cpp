#include "Quiz.h"


Quiz::Quiz(size_t maxQuestions) : size(0), capacity(maxQuestions)
{
	questions = new Question[capacity]; //capacity x Question()
}

Quiz::Quiz(const Quiz& other) : size(other.size), capacity(other.capacity)
{
	copyDynamic(other);
	//Очакваме всеки question да се копира с копиращ констр
	// деф констр + оп= !!! Проблем 
}
Quiz& Quiz::operator=(const Quiz& other)
{
	if (this != &other)
	{
		size = other.size;
		capacity = other.capacity;

		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}

Quiz::~Quiz()
{
	freeDynamic();
}

void Quiz::addQuestion(const Question& q)
{
	if (size >= capacity)
		return; //silent exit
	questions[size++] = q; /// op=  (  :////// ) 
}

size_t Quiz::getSize() const
{
	return size;
}

size_t Quiz::isFull() const
{
	return size == capacity;
}

void Quiz::copyDynamic(const Quiz& other)
{
	questions = new Question[other.capacity]; // //capacity x Question()
	for (int i = 0; i < other.capacity; i++)
		questions[i] = other.questions[i]; // capacity x op=

}

void Quiz::freeDynamic()
{
	delete[] questions; // capacity * ~Question() !!!!
}
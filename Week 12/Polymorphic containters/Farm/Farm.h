#pragma once

class Animal; //no need to include it. Just pointers 
class Farm
{
public:
	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	~Farm();

	void addAnimal(Animal* animal);      //will take ownership of the object
	void addAnimal(const Animal* animal);// will copy the object

	void roarAll() const;
	int getTypeCode(int index) const; // Bad design to have such function!

private:

	void resize();
	void freeDynamic();
	void copyDynamic(const Farm& other);

	Animal** animals = nullptr;
	size_t capacity = 0;
	size_t count = 0;
};


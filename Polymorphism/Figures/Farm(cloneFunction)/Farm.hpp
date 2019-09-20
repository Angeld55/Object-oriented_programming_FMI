#include "Animal.hpp"

// Collection of all animals
class Farm
{
	Animal** animals;
	int len;
	int count;
	void Free();
	void CopyFrom(const Farm& other);
	bool AddAnimal(Animal* an);
public:
	Farm(int len);
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	~Farm();
	bool AddCat(std::string name);
	bool AddDog(std::string name);
	bool AddCow(std::string name);
	void RoarAll();
};
Farm::Farm(int len)
{
	animals = new Animal*[len];
	this->len = len;
	count = 0;
}
Farm::Farm(const Farm& other)
{
	CopyFrom(other);
}
Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Farm::~Farm()
{
	Free();
}
bool Farm::AddAnimal(Animal* an)
{
	if(count == len)
		return false;
	animals[count++]=c;
	return true;
}
bool Farm::AddCat(std::string name)
{
	Cat* c = new Cat(name);
	if(!AddAnimal(c))
	{
		delete c;
		return false;
	}
}
bool Farm::AddDog(std::string name)
{
	Dog* c = new Dog(name);
	if(!AddAnimal(c))
	{
		delete c;
		return false;
	}
}
bool Farm::AddCow(std::string name)
{
	Cow* c = new Cow(name);
	if(!AddAnimal(c))
	{
		delete c;
		return false;
	}
}
void Farm::RoarAll()
{
	for (int i = 0; i < count; i++)
		animals[i]->Roar();  //roar is a virtual function 
	
}
void Farm::Free()
{
	for (int i = 0; i < count; i++)
		delete animals[i]; //~Animal() is virtual
	delete[] animals;
}
void Farm::CopyFrom(const Farm& other)
{
	animals = new Animal*[other.len];
	for (int i = 0; i < other.count; i++)
		animals[i] = other.animals[i]->clone(); //clone is a virtual function
	len = other.len;
	count = other.count;
}
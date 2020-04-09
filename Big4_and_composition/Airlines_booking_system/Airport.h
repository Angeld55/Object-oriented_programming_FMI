#include <iostream>

class Airport
{

	char* cityName;
	char id[4];

	void CopyFrom(const Airport& other);
	void Free();

public:

	Airport(const char* cityName,const  char* id);
	Airport(const Airport& other);
	Airport& operator=(const Airport& other);
	~Airport();

	const char* getId() const;
	const char* getCityName() const;
	void print() const;
};
#include <iostream>

const int maxCM = 99;
const int minCM = 0;
const int maxM = 999;
const int minM = 0;
const int minKm = 0;

class Distance
{
	int cm;
	int m;
	int km;
	
public:
	Distance();
	Distance(int km, int m, int cm);
	Distance(int cm);
	
	int getCm() const;
	int getM() const;
	int getKm() const;
	
	void setCm(int cm);
	void setM(int m);
	void setKm(int km);
	
	void Print() const;
	bool isGreedy() const;
	int convertToCm() const;
};

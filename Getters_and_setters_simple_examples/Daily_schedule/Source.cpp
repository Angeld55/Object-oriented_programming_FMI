#include <iostream>
using namespace std;


#include "Schedule.h"
 //абстракция 
 //капсулация ->

// дневен Орг -> събития 
// Събитие -> начален час и краен час
// Модификатори за достъп: private, public:
// Клас: Структура, при която мод. за достъп е private по default



int main()
{
	
	Schedule s;
	
	cout<< s.AddEvent("Party", 22, 30, 00, 23, 30, 00);

	cout<< s.AddEvent("Uni", 12, 00, 00, 14, 00, 00);

	s.AddEvent("Lunch", 11, 30, 00, 12, 00, 00);
	s.Print();
	cout << "after remove"<<endl;
	s.RemoveEvent(12,00,00,14,00,00);

	s.Print();


	
	


}
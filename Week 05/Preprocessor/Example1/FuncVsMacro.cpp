#include <iostream>
#include <string.h>
#include <ctime>

//example for a macro
#define MAX(a,b) (a>b ? a : b)

using namespace std;


int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	clock_t begin = clock();

	for (int i = 0; i < 10000000; i++)
		max(4, 10); //  inline?

	clock_t end = clock();
	cout << "10000000 calls of max function: " << double(end - begin)<<endl;

	begin = clock();
	for (int i = 0; i < 10000000; i++)
		MAX(4, 10);
	end = clock();
	cout << "10000000 times with macro: " << double(end - begin)<<endl;
	return 0;
}

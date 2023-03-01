

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*********************************************************************
#include <iostream>
#include <fstream>
#include <assert.h>


union IpAddress
{
	uint32_t address;
	unsigned char octets[4];
};


int main()
{
	IpAddress myAddress;
	myAddress.address = 16777343;
	
	std::cout << (int)myAddress.octets[0] << "." 
	          << (int)myAddress.octets[1] << "." 
	          << (int)myAddress.octets[2] << "." 
	          << (int)myAddress.octets[3];
	
}




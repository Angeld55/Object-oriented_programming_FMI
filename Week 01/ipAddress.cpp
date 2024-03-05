#include <iostream>
#include <fstream>

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

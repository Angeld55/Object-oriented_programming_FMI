#include <iostream>
#include <fstream>
#include "HexViewer.h"
using namespace std;

int main()
{
	HexViewer h("MyNumber2.dat");

	h.print();
	h.addByte("FF");
	h.print();

	h.removeLastByte();
	h.print();

	h.changeByte(3, "63");
	h.print();

}
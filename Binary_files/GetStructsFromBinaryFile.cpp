#include <iostream>
#include <fstream>
using namespace std;

struct test
{
	char ch;
	int num;
};

int GetFileSize(ifstream& ifs)
{
	ifs.seekg(0, std::ios::end); //отиваме в края на файла
	int size = ifs.tellg(); //запазваме коя е текущата позиция(тя всъщност е и размерът на файла)
	ifs.seekg(0, std::ios::beg); //връщаме се в началото на файла  
	return size;
//тази функция е хубаво да я извикваме преди да сме чели каквото и да е от файла, понеже ще се върнем в началото и ще загубим информация до къде сме стигнали с четенето
}

 
int main()
{
	std::ifstream inF("Structs.bat", std::ios::binary);

	if (!inF.is_open())
		return false;

	int fileSize = GetFileSize(inF); // взимаме големината на файла
	int objectCount = fileSize / sizeof(test); // намираме броя на обектите записани във файла

	test* arr = new test[objectCount];

	inF.read((char*)arr, fileSize); //директно ги четем в масива

	if (!inF)
	{
		cout << "Error occurred while reading from the file";
		return 1;
	}
	inF.close();

	for (int i = 0; i < objectCount; i++)
		cout << arr[i].ch << " " << arr[i].num << endl;
	delete[] arr;

	return 0;
}
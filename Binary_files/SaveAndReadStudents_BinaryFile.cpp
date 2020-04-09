#include <iostream>
#include <fstream>

using namespace std;
void SaveStudent(const char* name, int fn, ofstream& f)
{
	 f.write((const char*)&fn, sizeof(int)); //sizeof(int) is 4
	 int strLen = strlen(name);
	 f.write((const char*)&strLen,sizeof(int));
	 f.write(name, strLen);
}
void ReadStudent(ifstream& f)
{
	 int fn;
	 f.read((char*)&fn, sizeof(int));

	 int nameLen;
	 f.read((char*)&nameLen, sizeof(int));

	 char* name = new char[nameLen + 1];
	 f.read(name, nameLen);
	 name[nameLen] = '\0';

 	cout << "Name: " << name << " Fn: " << fn << endl;
	 delete[] name;

}



int main()
{
 //ofstream f;
 // f.open("students.bat");
 // SaveStudent("Ivan",123,f);
 // SaveStudent("Sasho",555,f);
 // f.close();

 //ifstream f2;
 //f2.open("students.bat");
 //ReadStudent(f2);
 //ReadStudent(f2);
 //f2.close();
 


}

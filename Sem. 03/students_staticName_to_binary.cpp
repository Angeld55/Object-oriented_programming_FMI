#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct Student
{
    char name[25];
    int fn;
    int age;
};

int main()
{
    { //write
        Student st;
        strcpy(st.name, "Ivan");
        st.fn = 1234;
        st.age = 33;
        
        ofstream file("student.dat", ios::binary);
        
        if (!file.is_open())
	{
		cout << "Error while writing to binary file!" << endl;
		return -1;
	}
        
        file.write((const char*)&st, sizeof(st));  //since the data is grouped in the struct, we can save it like this.
    }
    
    { //read
        Student st;
        ifstream file("student.dat", ios::binary);
        
        if (!file.is_open())
	{
		cout << "Error while reading from binary file!" << endl;
		return -1;
	}

        file.read((char*)&st, sizeof(st));
        
        std::cout << st.name << " " << st.fn << " " << st.age << std::endl;
    }
    return 0;
}

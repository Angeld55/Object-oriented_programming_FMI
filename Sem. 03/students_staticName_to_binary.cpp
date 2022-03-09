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
        
        file.write((const char*)&st, sizeof(st));
    }
    
    { //read
        Student st;
        ifstream file("student.dat", ios::binary);

        file.read((char*)&st, sizeof(st));
        
        std::cout << st.name << " " << st.fn << " " << st.age << std::endl;
    }
    return 0;
}

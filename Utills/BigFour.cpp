
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    char* name;
    int* grades;
    size_t gradesSize;
    
    void free()
    {
        delete[] name, grades;
    }
    
    void copyFrom(const Student& other)
    {
        setName(other.name);
        setGrades(other.grades);
    }
    
    public:
    
    Student() : name(nullptr), grades(nullptr) {}
    
    Student(const Student& other)
    {
        copyFrom(other);
    }
    
    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
        	free();
        	copyFrom(other);
        }
        return *this;
    }
    
    ~Student()
    {
        free();
    }
    
    const char* getName() const
    {
        return name;
    }
    
    const int* getGrades() const
    {
        return grades;
    }
    
    void setName(const char* givenName)
    {
        if(givenName == nullptr || givenName == name)
             return;
        delete[] name;
        name = new char[strlen(givenName) + 1];
        strcpy(name, givenName);
    }
    
    void setGrades(const int* givenGrades, size_t size)
    {
        if(givenGrades == nullptr || givenGrades == grades)
              return;

        delete[] grades;
        
        grades = new int[size];
        for(size_t i = 0; i< size; i++)
            grades[i] = givenGrades[i];
        gradesSize = size;
    }
    
    
};

int main()
{


    return 0;
}


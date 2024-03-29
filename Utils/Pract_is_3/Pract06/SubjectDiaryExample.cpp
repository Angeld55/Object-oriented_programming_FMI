#include <iostream>

#pragma warning (disable:4996)

struct Subject
{
private:

    char* name = nullptr;
    unsigned* grades = nullptr;
    unsigned countGrades = 0;

    void copy(const Subject& other)
    {
        unsigned size = strlen(other.name);
        name = new char[size + 1];
        strcpy(name, other.name);

        countGrades = other.countGrades;
        grades = new unsigned[countGrades];
        for (unsigned i = 0; i < countGrades; i++)
        {
            grades[i] = other.grades[i];
        }
    }

    void destroy()
    {
        delete[] name;
        delete[] grades;
        name = nullptr;
        grades = nullptr;
        countGrades = 0;
    }

public:
    Subject() = default;

    Subject(const char* name, const unsigned* grades, unsigned countGrades)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->grades = new unsigned[countGrades];
        for (size_t i = 0; i < countGrades; i++)
        {
            this->grades[i] = grades[i];
        }

        this->countGrades = countGrades;
    }

    Subject(const Subject& other)
    {
        copy(other);
    }

    Subject& operator=(const Subject& other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Subject()
    {
        destroy();
    }
};

struct Diary
{
private:

    Subject* subjects = nullptr;
    unsigned count = 0;

    void copy(const Diary& other)
    {
        count = other.count;
        subjects = new Subject[count];
        for (size_t i = 0; i < count; i++)
        {
            subjects[i] = other.subjects[i];
        }
    }
    void destroy()
    {
        delete[] subjects;
    }

public:
    Diary(const Subject* subjects, unsigned count)
    {
    }

    Diary(const Diary& other)
    {
        copy(other);
    }

    Diary& operator=(const Diary& other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Diary()
    {
        destroy();
    }

};




int main()
{
    unsigned grades[] = { 2,3,4 };
    Subject s1("Math", grades, 3);

    s1 = s1;
}

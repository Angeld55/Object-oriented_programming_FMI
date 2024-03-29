#include <iostream>

#pragma warning (disable:4996)

struct Subject
{
    char* name = nullptr;
    unsigned* grades = nullptr;
    unsigned countGrades = 0;

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

    ~Subject()
    {
        delete[] name;
        delete[] grades;
        name = nullptr;
        grades = nullptr;
        countGrades = 0;
    }
};

struct Diary
{
    Subject* subjects = nullptr;
    unsigned count = 0;

    Diary() = default;

    Diary(const Subject* subjects, unsigned count)
    {
        this->subjects = new Subject[count];

        for (size_t i = 0; i < count; i++)
        {
            // this->subjects[i] = subjects[i]; first show this and explain why it blows


            /*this->subjects[i].name = new char[strlen(subjects[i].name) + 1];
            strcpy(this->subjects[i].name, subjects[i].name);

            this->subjects[i].grades = new unsigned[subjects[i].countGrades];
            for (size_t j = 0; j < subjects[i].countGrades; j++)
            {
              this->subjects[i].grades[j] = subjects[i].grades[j];
            }

            this->subjects[i].countGrades = subjects[i].countGrades;*/ //second show this and explain why is bad

        }

        this->count = count;
    }

    ~Diary()
    {
        delete[] subjects;
        subjects = nullptr;
        count = 0;
    }
};


int main()
{
    unsigned grades[] = { 2,3,4 };
    Subject s1("Math", grades, 3);


    Subject subjects[] = { {"Math", grades, 3} };

    Diary d(subjects, 1);
    
    {
        Diary d1 = d; // third show this and explain why it blows
    }
    
    //fourth explain why we need big four
}
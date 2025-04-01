#include "GraduatedStudent.h"
#include <cstring>
#pragma warning(disable: 4996)

void GraduatedStudent::copyDynamic(const GraduatedStudent& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    grades = new int[other.gradesCount];
    for (int i = 0; i < other.gradesCount; i++)
        grades[i] = other.grades[i];
}

void GraduatedStudent::freeDynamic()
{
    delete[] name;
    delete[] grades;
    name = nullptr;
    grades = nullptr;
    gradesCount = 0;
    strcpy(quote, "");
}

GraduatedStudent::GraduatedStudent(const char* name, const int* grades, size_t gradesCount, const char* quote)
{
    setName(name);
    setGrades(grades, gradesCount);
    setQuote(quote);
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& other)
    : gradesCount(other.gradesCount)
{
    copyDynamic(other);
    strcpy(quote, other.quote);
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& other)
{
    if (this != &other)
    {
        freeDynamic();
        gradesCount = other.gradesCount;
        strcpy(quote, other.quote);
        copyDynamic(other);
    }
    return *this;
}

GraduatedStudent::~GraduatedStudent()
{
    freeDynamic();
}

void GraduatedStudent::setName(const char* newName)
{
    if (!newName || newName == name)
        return;
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void GraduatedStudent::setGrades(const int* newGrades, size_t newGradesCount)
{
    if (!newGrades || grades == newGrades)
        return;
    delete[] grades;
    grades = new int[newGradesCount];
    gradesCount = newGradesCount;
    for (int i = 0; i < newGradesCount; i++)
        grades[i] = newGrades[i];
}

void GraduatedStudent::setQuote(const char* newQuote)
{
    if (!newQuote || strlen(newQuote) > 30)
        return;
    strcpy(quote, newQuote);
}

const char* GraduatedStudent::getName() const
{
    return name;
}

const int* GraduatedStudent::getGrades() const
{
    return grades;
}

unsigned GraduatedStudent::getGradesCount() const
{
    return gradesCount;
}

const char* GraduatedStudent::getQuote() const
{
    return quote;
}

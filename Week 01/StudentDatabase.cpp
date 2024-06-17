#include <iostream>
#include <assert.h>

enum class Major
{
    undefined,
    Inf,
    Cs,
    InfS,
    S
};

const char* getMajorStr(Major m)
{
    switch (m)
    {
    case Major::Inf: return "Inf";
    case Major::Cs: return "Cs";
    case Major::InfS: return "InfS";
    case Major::S: return "S";

    }
    return "";
}

struct Student
{
    char name[100] = "";
    unsigned fn = 0;
    Major major = Major::undefined;
};

void printStudent(const Student& st)
{
    std::cout << st.name << " " << st.fn << " " << getMajorStr(st.major) << std::endl;
}

const int STUDENTS_MAX_SIZE = 10;
struct StudentDatabase
{
    unsigned studentsCount = 0;
    Student students[STUDENTS_MAX_SIZE];
};

void sortStudents(StudentDatabase& database)
{
    assert(database.studentsCount <= STUDENTS_MAX_SIZE);
}

void printDatabase(const StudentDatabase& database)
{
    assert(database.studentsCount <= STUDENTS_MAX_SIZE);

    for (int i = 0; i < database.studentsCount; i++)
        printStudent(database.students[i]);
}

enum class Criteria
{
    sortByName,
    sortByMajor,
    sortByFn
};

void sortDatabase(StudentDatabase& database, bool(*isLess)(const Student& lhs, const Student& rhs))
{
    for (int i = 0; i < database.studentsCount - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < database.studentsCount; j++)
        {
            if (isLess(database.students[j], database.students[minIndex]))
                minIndex = j;

        }
        if (i != minIndex)
            std::swap(database.students[i], database.students[minIndex]);
    }
}

void sortByCriteria(StudentDatabase& database, Criteria cr)
{
    switch (cr)
    {
    case Criteria::sortByName: return sortDatabase(database, [](const Student& lhs, const Student& rhs) { return strcmp(lhs.name, rhs.name) < 0; });
    case Criteria::sortByMajor: return sortDatabase(database, [](const Student& lhs, const Student& rhs) { return lhs.major < rhs.major; });
    case Criteria::sortByFn: return sortDatabase(database, [](const Student& lhs, const Student& rhs) { return lhs.fn < rhs.fn; });
    }
}

int main()
{
    StudentDatabase s =
    {
        3,
        {
            {"Petur", 12, Major::InfS},
            {"Ivan", 12345, Major::Cs},
            {"Aleksandur", 56, Major::S}
        }
    };

    printDatabase(s);

    sortByCriteria(s, Criteria::sortByName);

    printDatabase(s);

    sortByCriteria(s, Criteria::sortByMajor);

    printDatabase(s);

    sortByCriteria(s, Criteria::sortByFn);

    printDatabase(s);
}

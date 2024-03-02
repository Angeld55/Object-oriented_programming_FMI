#include <iostream>
#include <fstream>
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
    for (int i = 0; i < database.studentsCount; i++)
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

void serializeStudent(std::ostream& os, const Student& st)
{
    os << st.name << std::endl << st.fn << std::endl << (int)st.major << std::endl;
}
void serialize(std::ostream& os, const StudentDatabase& database)
{
    os << database.studentsCount << std::endl;
    for (int i = 0; i < database.studentsCount; i++)
        serializeStudent(os, database.students[i]);
}

void deserialize(std::istream& ifs, Student& st)
{
    ifs.ignore(); //there was a number on row before the string!!!!
    ifs.getline(st.name, 100);
    ifs >> st.fn;
    int tempMajor;
    ifs >> tempMajor;
    st.major = (Major)tempMajor;
}
StudentDatabase deserialize(std::istream& ifs)
{
    StudentDatabase st;
    ifs >> st.studentsCount;
    for (int i = 0; i < st.studentsCount; i++)
        deserialize(ifs, st.students[i]);
    return st;
}
int main()
{
    {
        std::ofstream ofs("students_to_text_file.txt");
        if (!ofs.is_open())
        {
            std::cerr << "Error while opening file for writing" << std::endl;
            return -1;
        }
        StudentDatabase db{ 3,
            "Ivan Popov", 12, Major::InfS,
            "Petur Aleksandrov", 3312, Major::S,
            "Kiril Petkov", 3312, Major::S
        };
        serialize(ofs, db);
    }
    {
        std::ifstream ifs("students_to_text_file.txt");
        if (!ifs.is_open())
        {
            std::cerr << "Error while opening file for writing" << std::endl;
            return -1;
        }

        StudentDatabase db = deserialize(ifs);
        serialize(std::cout, db); //print to the console
    }
}

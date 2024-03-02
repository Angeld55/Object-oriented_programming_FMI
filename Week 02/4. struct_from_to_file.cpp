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

struct Student
{
    char name[100] = "";
    unsigned fn = 0;
    Major major = Major::undefined;
};



const int STUDENTS_MAX_SIZE = 10;
struct StudentDatabase
{
    unsigned studentsCount = 0;
    Student students[STUDENTS_MAX_SIZE];
};

void serializeStudent(std::ostream& os, const Student& st)
{
    os << st.name << std::endl << st.fn << std::endl << (int)st.major << std::endl;
}
void serializeDatabase(std::ostream& os, const StudentDatabase& database)
{
    os << database.studentsCount << std::endl;
    for (int i = 0; i < database.studentsCount; i++)
        serializeStudent(os, database.students[i]);
}

void deserializeStudent(std::istream& ifs, Student& st)
{
    ifs.ignore(); //there was a number on row before the string!!!!
    ifs.getline(st.name, 100);
    ifs >> st.fn;
    int tempMajor;
    ifs >> tempMajor;
    st.major = (Major)tempMajor;
}
StudentDatabase deserializeDatabase(std::istream& ifs)
{
    StudentDatabase st;
    ifs >> st.studentsCount;
    for (int i = 0; i < st.studentsCount; i++)
        deserializeStudent(ifs, st.students[i]);
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
        serializeDatabase(ofs, db);
    }
    {
        std::ifstream ifs("students_to_text_file.txt");
        if (!ifs.is_open())
        {
            std::cerr << "Error while opening file for writing" << std::endl;
            return -1;
        }

        StudentDatabase db = deserializeDatabase(ifs);
        serializeDatabase(std::cout, db); //print to the console
    }
}

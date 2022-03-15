#include <iostream>
#include <fstream>

using namespace std;


struct Student
{
    char* name;
    int fn;
    int gradesCount;
    double averageGrade;
};
void print(const Student& st)
{
    cout << st.name << " " << st.fn << " " << st.gradesCount << " " << st.averageGrade << endl;
}
Student createStudent(const char* name, int fn, int gradesCount, double avGrade)
{
    Student obj;

    size_t nameLen = strlen(name);

    obj.name = new char[nameLen + 1];
    strcpy(obj.name, name);

    obj.fn = fn;
    obj.gradesCount = gradesCount;
    obj.averageGrade = avGrade;

    return obj;
}
void saveStudentToFile(ofstream& f, const Student& st)
{
    size_t nameLen = strlen(st.name);

    f.write((const char*)&nameLen, sizeof(nameLen));  //first we write the size of the name!
    f.write(st.name, nameLen);

    f.write((const char*)&st.fn, sizeof(st.fn));
    f.write((const char*)&st.gradesCount, sizeof(st.gradesCount));
    f.write((const char*)&st.averageGrade, sizeof(st.averageGrade));

}
Student readStudentFromFile(ifstream& f)
{
    Student res;

    size_t nameLen;

    f.read((char*)&nameLen, sizeof(nameLen)); //first we read the size of the name!

    res.name = new char[nameLen + 1];
    f.read(res.name, nameLen);
    res.name[nameLen] = '\0';

    f.read((char*)&res.fn, sizeof(res.fn));
    f.read((char*)&res.gradesCount, sizeof(res.gradesCount));
    f.read((char*)&res.averageGrade, sizeof(res.averageGrade));

    return res;
}
void freeStudent(Student& s)
{
    delete[] s.name;

    s.averageGrade = s.fn = s.gradesCount = 0;

}


int main()
{
    { //save students to file
        Student s1 = createStudent("Ivan", 1234, 2, 4);
        Student s2 = createStudent("Petur", 5555, 5, 5.5);

        ofstream f1("uni.dat", ios::binary);

        if (!f1.is_open())
        {
            cout << "Error" << endl;
            return -1;
        }

        saveStudentToFile(f1, s1);
        saveStudentToFile(f1, s2);

        freeStudent(s1);
        freeStudent(s2);

        f1.close();
    }

    { //read students from file
        ifstream f2("uni.dat", ios::binary);

        if (!f2.is_open())
        {
            cout << "Error" << endl;
            return -1;
        }
        Student s1 = readStudentFromFile(f2);
        Student s2 = readStudentFromFile(f2);

        print(s1);
        print(s2);

        freeStudent(s1);
        freeStudent(s2);

        f2.close();
    }
}




#  Структури и двоични файлове.
###  Размер на структура:
 ```c++
#include <iostream>
using namespace std;

struct A 
{
  int a;
  int b;
};

int main()
{
    cout << sizeof(A) << endl; // 8 bytes (4 bytes for each int)

    return 0;
}
 ```
 
 Ето как изглежда структурата в паметта:
 
 
 ![enter image description here](https://i.ibb.co/9yWmQjP/2.png)
 
Пример за **естествено подравняване**:

 ```c++
#include <iostream>

using namespace std;

struct B 
{
  char ch;
  int a;
};

int main()
{
    cout << sizeof(B); // 8 byte-s

    return 0;
}

 ```
 В паметта нещата изглеждат така:
 
![enter image description here](https://i.ibb.co/zJ5bLCw/pic1.png)

###  Подравняване 
При представянето на обект (от някакъв тип) в паметта:

-  В паметта променливите са разположени **в същия ред**, в който са декларирани в структурата.
 - Подравняването става по **големината на най-голямата примитивна член-променлива** на структурата - размерът на структурата трябва да се дели на размерзът на най-голямата променлива.
 - *Неформално*: Всяка променлива трябва да е на байт (ако приемем, че байтовете имат индекс, започвайки от 0), който е **кратен на големината на променливата**.
 
 За постигане на най-компактно представяне полетата на структурата да се сортират по тяхната големина в низходящ ред

###  Пример за записване на обекти във файл.
 ```c++
#include <iostream>
#include <fstream>
using namespace std;

struct Test
{
  char ch;
  int a;
};
int main()
{
    ofstream f("output.dat", ios::binary);
    
    if(!f.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    
    Test arr[3] = {{'a', 400},{'b', 500},{'c', 600}};
    
    f.write((const char*)&arr, sizeof(arr));
    
    f.close();
    
    return 0;
}

 ```

След изпълнението на програмата, файлът (**output.dat**) изглежда така:

![Image of the binary file after running the code](https://i.ibb.co/0JthLd6/3-A978-D14-7-C7-A-4-ABD-8-B0-C-DA27-F6-E9-CD0-A.png "Binary file")

 


#  Структури и двоични файлове.
###  Размер на структура:
 ```c++
#include <iostream>
using namespace std;

struct A 
{
  int a;
  int b;
};

int main()
{
    cout << sizeof(A) << endl; // 8 bytes (4 bytes for each int)

    return 0;
}
 ```
 
 Ето как изглежда структурата в паметта:
 
 
 ![enter image description here](https://i.ibb.co/9yWmQjP/2.png)
 
Пример за **естествено подравняване**:

 ```c++
#include <iostream>

using namespace std;

struct B 
{
  char ch;
  int a;
};

int main()
{
    cout << sizeof(B); // 8 byte-s

    return 0;
}

 ```
 В паметта нещата изглеждат така:
 
![enter image description here](https://i.ibb.co/zJ5bLCw/pic1.png)

###  Подравняване 
При представянето на обект (от някакъв тип) в паметта:

-  В паметта променливите са разположени **в същия ред**, в който са декларирани в структурата.
 - Подравняването става по **големината на най-голямата примитивна член-променлива** на структурата - размерът на структурата трябва да се дели на размерзът на най-голямата променлива.
 - *Неформално*: Всяка променлива трябва да е на байт (ако приемем, че байтовете имат индекс, започвайки от 0), който е **кратен на големината на променливата**.
 
 За постигане на най-компактно представяне полетата на структурата да се сортират по тяхната големина в низходящ ред

###  Пример за записване на обекти във файл.
 ```c++
#include <iostream>
#include <fstream>
using namespace std;

struct Test
{
  char ch;
  int a;
};
int main()
{
    ofstream f("output.dat", ios::binary);
    
    if(!f.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    
    Test arr[3] = {{'a', 400},{'b', 500},{'c', 600}};
    
    f.write((const char*)&arr, sizeof(arr));
    
    f.close();
    
    return 0;
}

 ```

След изпълнението на програмата, файлът (**output.dat**) изглежда така:

![Image of the binary file after running the code](https://i.ibb.co/0JthLd6/3-A978-D14-7-C7-A-4-ABD-8-B0-C-DA27-F6-E9-CD0-A.png "Binary file")



###  Пример за записване на обекти, които съдържат динамично заделени данни, във файл.
 ```c++
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

	f.read((char *)&nameLen, sizeof(nameLen)); //first we read the size of the name!

	res.name = new char[nameLen + 1];
	f.read(res.name, nameLen);
	res.name[nameLen] = '\0';

	f.read((char *)&res.fn, sizeof(res.fn));
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
 

 ```

### Задачи

**Задача 1:** Да се реализира система за база данни **произволен брой унивеситети** с университети. Всеки университет има име (низ до 32 символа) множество от студенти. Всеки студент има - Име (**низ с произволна дължина**), факултетен номер, брой получени оценки и средна оценка. След зареждане на данните в паметта, релизирайте следнита функции:

- По подадено име на университет и факултетен номер на студент, променя името на студента. 

changeName(const char* uni, int fn, const char* newName);

- Добавяне на оценка на даден студент. След добавянето на оценката, трябва да се обнови броят получени оценки и средната оценка.

 addGrade(const char* uni, int fn, int grade)

- Функция, която сортира университите по среден успех на студентите.

sort(unis*, size_t unisCount)


### Задачи

**Задача 1:** Да се реализира система за база данни **произволен брой унивеситети** с университети. Всеки университет има име (низ до 32 символа) множество от студенти. Всеки студент има - Име (**низ с произволна дължина**), факултетен номер, брой получени оценки и средна оценка. След зареждане на данните в паметта, релизирайте следнита функции:

- По подадено име на университет и факултетен номер на студент, променя името на студента. 

**changeName(const char* uni, int fn, const char* newName)**

- Добавяне на оценка на даден студент. След добавянето на оценката, трябва да се обнови броят получени оценки и средната оценка.

 **addGrade(const char* uni, int fn, int grade)**

- Функция, която сортира университите по среден успех на студентите.

**sort(uni *, size_t unisCount)**





##  Текстови файлове
Видове потоци:
 - Потоци за вход (istream)
 - Потоци за изход (ostream)

#####  Пример за работа с поток за вход (cin)
 ```c++
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
}
 ```
 Четем от стандартния вход.

#####  Пример за работа с поток за изход (cout)
 ```c++
#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 12;
	int c = a + b;

	cout << a << " + " << b << " = " << c << endl;
}
 ```
	
### Работа с поток за вход от файл (ifstream)
Пример за четене от файл!
 ```c++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file("myFile.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}
	int a, b;

	file >> a >> b;

	file.close();
}
```
### Работа с поток за изход към файл (ifstream)
   
 ```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream file("myFile.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}
	int a = 3;
	int b = 10;

	file << a << " " << b << " " << a + b << endl;

	file.close();
}
 ```
**Задача 1**:

Напишете програма, която отпечатва собствения си код.

**Задача 2**:

Напишете програма,  която чете comma-separated values (**CSV**) файл със студенти **със следните 4 полета**: Първо име, Фамилно име, Имейл, Факултетен номер.
**Примерен файл:** (students.csv).

**Домашна работа**:

 1. Допълните примера от семинара да чете факултетните номера на студентите.
2. Направете функция, която след зареждане на файла, да отпечатва на **стандартния изход** информация за студента при подаден **факултетен номер**.
3.  Напишете функция, която приема editFirstNamе, която **по подаден факултетен номер  и низ**, да променя първото име на студента с дадения факултетен номер първото име с подадения низ.
4.  Променете функцията **saveStudentsToFile** за да запазва студентите в същия формат (**CSV**). Т.е. при повторно пускане на програмата да може да прочете новият генериран файл.


Да се реализира прост интерфейс, с който да се извикват фунцкиите през конзолата:
Пример (входът от потребителя започва с '>')

 ```
>open students.csv
>print 80000
Name = Stefan Velkov, Email: stefan@yahoo.com, FN: 80000
>edit 8000 Krum
>print 80000
Name = Krum Velkov, Email: stefan@yahoo.com, FN: 80000
>save
file students.csv successfully saved!
```
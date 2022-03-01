
##  Потоци и Файлове (част 1). Текстови файлове.
Видове потоци:
 - Потоци за вход (istream).
 - Потоци за изход (ostream).
 
![enter image description here](https://i.ibb.co/VDdDSnM/potoci.gif)


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
Пример за прочитане на цялото съдържание файл:
 ```c++
#include <iostream>
#include <fstream>
using namespace std;

const int BUFF_SIZE = 1024;
int main()
{
	ifstream file("myFile.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}
	while (!file.eof())
	{
		char buff[BUFF_SIZE];
		file.getline(buff, BUFF_SIZE);
		
		//do something with the line
		cout << buff<< endl;
	}
	file.close();
}
```
### Работа с поток за изход към файл (ofstream)
   
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
	
	if(!file.eof()) //check if the file has ended
		cout << "The file contains more data after the two integers!" << endl;

	file.close();
}
 ```

 - ifstream или istream - get указател, който реферира елемента, който ще се прочете при следващата входна операция. 

 - ofstream или ostream - put указател, който реферира мястото, където ще се запише следващият елемент.

### Режими на работа

 ```c++
	ifstream str("file.txt", <режим на работа>).
 ```
Режимът на работа е цяло число. 

| ios         | Ефект:                                                                                                                           |    |
|-------------|----------------------------------------------------------------------------------------------------------------------------------|----|
| ios::in     | Отваря файл за извличане.                                                                                                        | 1  |
| ios::out    | Отваряне на файл за вмъкване. Допуска се вмъкване на произволни места във файла. Ако файлът съществува, съдържанието се изтрива. | 2  |
| ios::ate    | Отваря за вмъкване и установява указателя put в края на файла. Допуска вмъкване на произволни места.                             | 4  |
| ios::app    | Отваря за вмъкване и установява указателя put в края на файла                                                                    | 8  |
| ios::trunc  | Ако файлът съществува, съдържанието се изтрива.                                                                                  | 16 |
| ios::binary | Превключва режима от текстов в двоичен                                                                                           | 32 |
 

 ```c++
	ostream file("file.txt", ios::out | ios::app).
 ```


 ##  Задачи
 
**Задача 1**: Напишете програма, която отпечатва собствения си код.

**Задача 2**: Напишете функция, която приема име на съществуващ файл и име и копира съдържанието на същестуващия файл в нов файл.

**Задача 3**: Напишете програма,  която чете comma-separated values (**CSV**) файл със студенти **със следните 4 полета**: Първо име, Фамилно име, Имейл, Факултетен номер.
1.  Със стартирането на програмата потребителят да въвежда име на файл, който да бъде зареден в паметта.
2.  Напишете функция, която след зареждане на файла да отпечатва на **стандартния изход** информация за студента при подаден **факултетен номер**.
3.  Напишете функция, която **по подаден факултетен номер и низ**, променя email-a на студента, който има дадения факултетен номер, с подадения низ.
4.  Напишете функцията , която приема низ (име на файл) и запазва студентите в същия формат (**CSV**). Т.е. при повторно пускане на програмата да може да прочете новия генериран файл.

Да се реализира прост интерфейс, с който да се извикват написаните фунцкии през конзолата:

**Пример** (входът от потребителя започва с '>'):

 ```
Open file: 
>students.csv
File successfully opened!
>print 80000
Name = Stefan Velkov, Email: stefan@yahoo.com, FN: 80000
>edit 80000 Krum
>print 80000
Name = Krum Velkov, Email: stefan@yahoo.com, FN: 80000
>save students2.csv
file students2.csv successfully saved!
```

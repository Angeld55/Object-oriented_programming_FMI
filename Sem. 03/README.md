# Файлове (част 2). Двоични файлове.

## Режими за работа с файлове


| Режим:| Ефект:                                                                      | 
|--------|------------------------------------------------------------------------------|
|ios::in |Отваря файл за четене  (по подразбиране на ifstream)                           |
|ios::out    |Отваря файл за четене (по подразбиране на ofstream)                        |
|ios::binary | Отваря файл в двоичен режим                                               |
|ios::trunc  | Ако файлът съществува,  съдържанието му се изтрива след отваряне на поток |
|ios::app    | Отваря файлът за вмъкване. Поставя put указателят в края. Не се допуска вмъкване преди края на потока      |
|ios::ate    | Отваря файлът за вмъкване. Поставя put указателят в края. Допуска вмъкване на прозиволни места                |
|ios::nocreate | Отваря за вмъкване, само ако файлът с указаното име съществува.|
ios::noreplace | Отваря за вмъкване само ако файлът с указаното име не съществува.|
### Пример:
 ```c++
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream f("test.txt", ios::out | ios::app);

	if (!f.is_open())
	{
		cout << "Error while opening file!" << endl;
		return -1;
	}
	f << 33; //appends at the end of the file

	f.close();
	return 0;
}
 ```
## Флагове на състоянията на потока 
| Флаг:| Значение:                                                                      | 
|--------|------------------------------------------------------------------------------|
|bad()   | Има загуба на информация. Някоя операция за четене и писане не е изпълнена. |
|fail() |Последната входно/изходна операция е невалидна.|
| eof() | Достигнат е края на файла. |
|good() | Всички операции са изпълнени успешно.|
|clear()| Изчиства състоянието на потока (Вече good() ще върне истина).|

## Позициониране във файл

 - tellg() - Връща позцития на текущия символ в **потока за четене**
 - tellp() - Връща позцития на текущия символ в **потока за писане**
 - seekg(offset, direction) - Премества get-указателят на позцития на **потока за четене**.
 - seekp(offset, direction) - Премества put-указателят на позцития на **потока за писане**.
 
 
 -**offset** : целочислена стойност. Отместването от direction.
 
 -**direction** : Може да заема следите стойностти:

1. ios::beg - началото на файла.
2. ios::cur - текущата позиция във файла.
3. ios::end - края на файла.

### Пример:
 ```c++
#include <iostream>
#include <fstream>
using namespace std;
size_t getFileLen(std::ifstream& ifs) //we can pass stream to functions.
{ 

	ifs.seekg(0, std::ios::end); //set the position at the end of the file
	size_t size = ifs.tellg(); //get the curren position
	ifs.seekg(0, std::ios::beg); //set the position at the beginning

	return size;
}
 ```
## Двоични файлове.

Изпоилзваме функциите:

1. .read(char* memoryBlock, size_t size);
2. .write(char* memoryBlock, size_t size);

Обърнете внимание, че функцията приема **char***. Ако искаме да запазим променлива от друг вид, ще трябва експлицитно да преобразуваме указателя към тип char* (без значение, че указателят не сочи към елементи от тип char)

### Пример за писане в двоичен файл:
 ```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream f("file.dat");

	int a = 155555;

	f.write((const char*)&a, sizeof(int));

	return 0;
}
 ```
 ### Пример за четене от двоичен файл:
 
  ```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream f("file.dat");

	int a;

	f.read((char*)&a, sizeof(int));

	cout << a << endl;

	return 0;
}
 ```

 ### Съдържанието на двоичния файл:
 ![enter image description here](https://i.ibb.co/G3R72qG/sudurjanie.png "Binary file example")
 
Байтовете се записват в **обратна посока**. Най-старшият байт е последен. Следователно запаментеното число е **00025fa3**, което е точно шестанйсетичния запис на числото **155555**.
 

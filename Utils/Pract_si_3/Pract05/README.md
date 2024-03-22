# Задачи

## Управление на служители във фирма

Разглежаме задача за създаване на проста система за управление на служители във фирма.

Ще дефинираме следния `enum class` за връщане на *state* на дадена операция:

```c++
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput
};
```
*Забележка: Ако се сетите за още някой възможен edge case, добавете съответния код за грешка.*

---

Ще имаме **три** класа:

### Клас `Employee`

#### Атрибути:

- `unsigned id`
- `char name[]` - низ с максимална дължина 127 символа;
- `char position[]` - низ с максимална дължина 127 символа;
- `double salary`

#### Методи:

- *Default-ен* конструктор.
- Конструктор с параметри.
- `double getSalary() const` - връща заплатата на служителя.
- `ErrorCode updateSalary(double amount)` - актуализира заплатата на служителя.

---

### Клас `Department`

#### Атрибути:

- `char name[]` - низ с максимална дължина 127 символа;
- `Employee employees[]` - масив с максималнa големина 15;
- `unsigned countOfEmployees`

#### Методи:

- *Default-ен* конструктор.
- Конструктор с параметри.
- `ErrorCode addEmployee(const Employee& employee)` - добавя служител към отдела.
- `ErrorCode removeEmployee(unsigned id)` - премахва служител от отдела.
  
---

### Клас `Company`

#### Атрибути:

- `Department departments[]` - масив с максималнa големина 10;
- `unsigned countOfDepartments`

#### Методи:

- Конструктор без параметри.
- `ErrorCode addDepartment(const char* name)` - добавя отдел към фирмата.
- `ErrorCode removeDepartment(const char* name)` - премахва отдел от фирмата.
- `ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee)` - добавя служител към определен отдел.
- `ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id)` - премахва служител от определен отдел.

<br>
  Реализирайте методите за всеки клас посредством дадените насоки. 
Методите трябва да се справят с грешките по коректен начин и да връщат подходящи кодове за грешки. 
Подредете член-данните си оптимално, така че да заемат минимално количество памет.

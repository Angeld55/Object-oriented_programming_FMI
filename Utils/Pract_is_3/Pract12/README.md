## Задача 1
Направете абстрактен базов клас `StringViewer` със следните методи:

* `char operator[](size_t ind) const`                       - връща даден символ
* `size_t length() const`                                   - връща дължината
* `bool isEmpty() const`                                    - връща дали е празен
* `void removeSuffix(size_t count)`                         - премахва от края произволен брой символи
* `void removePreffix(size_t count)`                        - премахва от началото произволен символи
* `StringViewer* substr(size_t pos, size_t count) const`   - връща подстринг
* `int indexOf(...) const`          - връща дали даден StringViewer е част от друг и връща index към началото, в противен случай връща -1
<br>
* Направете функция `compare`, която сравнява произволни два наследника на StringViewer
* Направете методи за принтиране на съдържанието на стринга в конзолата

<br>
Помислете кои трябва да са виртуални и кои не.

Направете следните наследници:

* `StringStraight` - Конструктори (const char*, const char*)/(const char*)/(const char*, size_t count)
* `StringReverse` - Конструктори (const char*, const char*)/(const char*)/(const char*, size_t count)
* `StringConcat`  - Конструктори (const StringViewer*, const StringViewer*)

Направете StringContainer, който представлява хетерогенен контейнер. Имплементирайте следните методи:
* `add(...)` - добавяне на елемент
* `filter(bool(*func)(...))` - филтрира елементите по даден критерий.


## Задача 2 Workflow Automation System


Създайте система за автоматизация на работния процес на различни видове задачи в бизнес процеса.

Базов клас: `Task`

Съдържа полета: `taskID, taskName, priority и status`.<br>
Където 
- `taskID` - уникален идентификатор за дадената задача.
- `taskName` - непразен низ
- `priority` - представлява приоритът на задачата. Стойностите са цели числа в интервала [1 - 10], като по-малко число значи по-голяма важност
- `status` - представя статусът на изпълнение на заявката. Може да бъде `Not Completed`, `Running` или `Completed`
Добавете функции `execute(), getStatus(), setPriority(int newPriority) и displayTaskInfo()`.


Наследници: `EmailTask`, `FileTransferTask`, `ReportGenerationTask`


`EmailTask`:<br>
Допълнителни полета: `recipient, subject, body`.


FileTransferTask:<br>
Допълнителни полета: `sourcePath, destinationPath, fileSize`.
- `sourcePath` - път до файла, който ще бъде преместен
- `destinationPath` - пътя на файла след изпълнението на задачата
- `fileSize` - размер на местения файл.


`ReportGenerationTask`:<br>
Допълнителни полета: `reportType, reportPeriod, outputFormat`.

- `reportType` - Годишен отчет, Месечен отчет, Предложение, Технически доклад (добавете и други видове по желание)
- `outputFormat` - `.docx`, `.xlsx`, `.pdf`, `.pptx`

Създайте клас `TaskCollection`, който представлява колекция от задачи.

Класът да поддържа методи за:
* добавяне на задача
* принтиране на задачите, които предстои да се изпълнят
* принтиране на изпълнените задачи (в реда, в който са били изпълнени)
* достъпване на задача, която още не е изпълнена (задачите в колекцията могат да сменят приоритета си)
* изпълняване на задача (изпълняват се спрямо техния приоритет: първо се изпълнява тази с най-висок приоритет)

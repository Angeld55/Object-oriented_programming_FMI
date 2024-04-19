
### Масиви от указатели към обекти.

 ```c++
class SomeCollection
{
	A** data;
	//other things
};
 ```
![enter image description here](https://i.ibb.co/YDCL2nr/pointer-Of-Pointers.png)
#####  Какви са ползите:

 - Бързо разместване на обектите в колецкията - не се изисква да се копират. Само разместваме указателите
 - Не се изисква същестуването на деф. контруктор на A.
 - Възможно е да имаме "празна клетка", като се възползваме от възможната nullptr стойност.

# Move semantics

## lvalue & rvalue
Всеки израз в C++ е lvalue или rvalue.
- lvalue - Именована променлива.
- rvalue - това са изрази, които не са lvalue

```c++
int a;
a = 4;    // = requires a (modifiable) lvalue as it's lhs, which is a
lvalue-тата могат и да не са променливи
```

lvalue-тата могат и да не са променливи
```c++
int x;

int& getRef() {
	return x;
}

int main() {
	getRef() = 4;  //Okay, getRef() is an lvalue - returns a reference to the global variable x
	return 0;
}
```
Тук getRef() връща референция към глобалната променлива x, която има адрес в паметта и е lvalue, т.е. всичко е наред. <br />
Колкото при rvalue-тата:

```c++
4 = var;        //Error
(var + 1) = 4;  //Error
```

В случая нито 4, нито (var + 1) са lvalue, а оттам хвърчи и грешката.
```c++
int x;

int getRef() {
	return x;
}

int main() {
	getRef() = 4;  //Error
}
```
Тук getRef() вече е rvalue - вместо да се връща референция към обекта x, се връща някакво негово локално копие.

## rvalue reference
Важният детайл дотук е, че rvalue изразите се отнасят главно към обекти, които са временни, т.е. са пред изтриване. Би било хубаво да можем по някакъв начин да можем да разпознаваме точно такива обекти, т.е. да разпознаваме дали някакъв израз връща някаква временна променлива и да го пренапишем по различен начин, ако случаят е такъв. Точно тук идва и ролята на rvalue референциите. <br />
До C++11 референции към константна rvalue са възможни, но те не могат да изменят обекта, т.е.

```c++
std::string getName() {
	return "Pesho";
}

const std::string& name = getName(); //ok
std::string& name = getName();       //not ok
```	
При C++11 се въвежда нов тип референция, а именно rvalue референцията, която позволява референция към rvalue. С други думи, rvalue референциите са идеалният начин за разпознаване дали една обект  е временен или не. За разлика от lvalue референциите, те се пишат с &&. <br />

```c++
int i = 42;
int &r = i; // ok: r refers to i
int &&rr = i; // error: cannot bind an rvalue reference to an lvalue

int &r2 = i * 42; // error: i * 42 is an rvalue
const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplication
```
Т.к. rvalue референциите могат да сочат единствено към временни обекти. Това означава, че код, който използва rvalue референция свободно може да си присвои ресурсите му. <br />
Въпреки, че rvalue референции не могат да сочат към lvalue-та, можем да cast-нем lvalue към xvalue(в съответстващата й rvalue референция)
```c++
int x = 5;
int&& xRRef = x;   //Error: rvalue reference cannot be bound to an lvalue

int&& xRRef = std::move(x);  //Ok
```

На практика move казва на компилатора да третира x като rvalue.(конвентира x ,който е lvalue, към xvalue) <br />

Добре, с какво ни помагат този вид референции? <br />
Ами, вече разполагаме с апарат, който еднозначно ни казва кога един израз е lvalue и кога е rvalue, т.е. можем да предефинираме една функционалност да работи по два различни начина - по един при работа с lvalue изрази, а по друг с rvalue такива.

```c++
void print(const std::string& str) {
        std::cout << str;
}
 
void print(std::string&& str) {
        std::cout << str;
}

std::string lString = "Pesho";

print(lString);  //Takes an lvalue, first function
print("Ivan");   //Takes an rvalue as a parameter, hence the second function will be instantiated
```

## Move конструктор & Move Assignment оператор

Move конструкторът, както и копи конструкторът, приема референция към същия тип, с разликата, че това е rvalue референция, при това неконстантна. <br />
Идеята е следната - при създаване на обекта, крадем ресурсите на обекта, към който е референцията и го оставяме в такова състояние, че последващото му изтриване да не навреди на новосъздадения обект. <br /> 
При примитивните типове данни това е просто копиране. Вече при указателите, при които наша имплементация на copy контрола би наложила дълбоко копиране, е малко по-различно. <br />

```c++
Student::Student(Student&& other) noexcept : name(other.name), age(other.age) {
	other.name = nullptr;   //Leaves toMove in a state that further destruction will do no harm!
}
```
Т.е. слагаме name да сочи към парчето памет, към което сочи toMove.name (а не заделяме наново динамична памет!), също казваме age = toMove.age. <br />
В тялото слагаме името на toMove да сочи към nullptr, т.е. при изтриване той няма да навреди по никакъв начин на обекта, в който местим ресурсите. <br />

```c++
Person& operator=(Person&& other) noexcept {
	if(this != &other) {
		free();	//Free the resources associated with this

		name = other.name;
		age = other.age;

		other.name = nullptr;  //put other in a state where deleting won`t cause problems in further uses of this
	}

	return *this;
}
```

## Синтезирани move операции
Както и при копи конструктура, copy assignment оператора и деструктура, компилаторът автоматично ще синтезира move конструктор и move assignment оператор. <br />
Единствената разлика тук е, че условията, при които той прави това са различни. <br />
За разлика от копи операциите, за някои класове компилаторът изобщо не създава move конструктор и move assignment оператор. <br />
В частност, ако един клас дефинира свой copy конструктор, copy assignment оператор или деструктор, то move конструкторът и copy assignment операторът няма да бъдат синтезирани. Aко един клас няма move операции, то се използват copy такива (даже върху временни обекти, като точно това целим да избегнем), ако такива има разбира се. <br />
Компилаторът ще създаде move конструктор и move assignment оператор ако класът няма дефиниран copy control и ако всеки член може да бъде "преместен". <br />
Компилаторът може да премества вградени типове, а също и класове, които имат съответната move операция дефинирана. При примитивните типове данни местенето е просто копиране. <br />
Aко експлицитно помолим компилатора да генерира move операция чрез =default, и компилаторът не успее да синтезира такъв, то той бива маркиран като =deleted.


// Голямта 4-ка - Функции, които трябва да разпишем, САМО когато имаме динамична памет в класа.

// 1.Defualt constructor InformaticsStudent();
// 2.Copy-constructor InformaticsStudent(const InformaticsStudent& other); 
// 3.operator=  InformaticsStudent& operator=(const InformaticsStudent& other);
// 4.Destructor ~InformaticsStudent()
// (Най-лесно е като си разпишем функция за копиране CopyFrom  и функция за триене Free())

class InformaticsStudent
{
private:
	char* name;
	int fn;

	void CopyFrom(const InformaticsStudent& other);
    void Free();

public:
	/// BIG 4 starts here
	InformaticsStudent();
	InformaticsStudent(const InformaticsStudent& other);
	InformaticsStudent& operator=(const InformaticsStudent& other);
	~InformaticsStudent();
	// BIG 4 ends here

	InformaticsStudent(const char* name, int fn);
	
	void setName(const char* name);
	void setFn(int fn);
	const char* getName() const;
	int getFn() const;
	
	void printStudent();
	
};

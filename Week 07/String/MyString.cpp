MyString operator+(const MyString& lhs, const MyString& rhs)
{
  //TBI
	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[length() + other.length() + 1];
	result[0] = '\0'; //заради strcat!!
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;
	size = length() + other.length();

	return *this;
}

MyString::MyString()
{
	_data = new char[1];
	_data[0] = '\0';
	size = 0;
}
MyString::MyString(const char* data)
{
	size = strlen(data);
	_data = new char[size + 1];
	strcpy(_data, data);
	
}
void MyString::free()
{
	delete[] _data;
	_data = nullptr;
}
MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return size; //!!!!
}

void MyString::copyFrom(const char* data)
{
	size = strlen(data);
	_data = new char[size + 1];
	strcpy(_data, data);
}

void f(const MyString& str)
{
	std::cout << str[0];
}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
	return _data[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
	return _data[index];
}

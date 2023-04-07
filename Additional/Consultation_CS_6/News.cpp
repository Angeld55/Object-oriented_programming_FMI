#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
 
class News
{
public:
	News(const char* filePath)
	{
		if (!filePath || strlen(filePath) >= 1024)
			return;
 
		strcpy(_filePath, filePath);
	}
 
private:
	char _filePath[1024] = "";
	unsigned _likes = 0;
	unsigned _dislikes = 0;
 
	friend std::ostream& operator<<(std::ostream& ofs, const News& current);
};
 
std::ostream& operator<<(std::ostream& os, const News& current)
{
	std::ifstream ifs(current._filePath);
 
	if (!ifs.is_open())
	{
		std::cerr << " Error! The file is not opened";
		return os;
	}
	while (ifs)
	{
		char buff[1024];
		ifs.getline(buff, 1024);
		os << buff;
	}
	return os;
}
 
//only move op= is missing.
class NewsSite
{
	News** _data;
	size_t _capacity; //колко е големината на масива от указатели
	size_t _count = 0; //колко елемента са добавени
 
	void free()
	{
		for (int i = 0; i < _count; i++)
			delete _data[i];
		delete[] _data;
	}
	void copyFrom(const NewsSite& other)
	{
		_count = other._count;
		_capacity = other._capacity;
 
		_data = new News*[_capacity];
		for (int i = 0; i < _count; i++)
		{
			_data[i] = new News(*other._data[i]);
		}
 
		/*
			_data = new News*[_capacity];
		for (int i = 0; i < _capacity; i++)
		{
			if(other._data[i] == nullptr)
				data[i] = nullptr
			else
				_data[i] = new News(*other._data[i]);
		}
 
 
		*/
 
	}
 
public:
	NewsSite(size_t capacity)
	{
		_capacity = capacity;
		_data = new News*[_capacity]{nullptr};
	}
 
	NewsSite(const NewsSite& other)
	{
		copyFrom(other);
	}
 
	NewsSite(NewsSite&& other) noexcept
	{
		_data = other._data;
		other._data = nullptr;
 
		_count = other._count;
		_capacity = other._capacity;
	}
 
	NewsSite& operator=(const NewsSite& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
 
	~NewsSite()
	{
		free();
	}
 
	void addNews(const News& current)
	{
		if (_count >= _capacity)
			return;
 
		_data[_count++] = new News(current);
 
 
		//int iter = _count;
		//while (_data[iter] != nullptr)  //since count is less then capactity, there should be at least one free slot
			//iter--;
 
		//_data[iter] = new News(current);
		//_count++;
 
	}
 
	void removeNews(size_t index)
	{
		if(index >= _count)
			return;
 		
		//check for nullptr if the order is not preserved
		std::swap(_data[index], _data[_count - 1]);
 
		delete _data[_count - 1];
		_data[_count - 1] = nullptr;
		_count--;
	}
 
	const News& operator[](size_t index) const 
	{
		return *_data[index];
	}
 
	News& operator[](size_t index)
	{
		return *_data[index];
	}
};
 
 
int main()
{
 
	
		NewsSite n1(8);
 
		n1.addNews(News("Novina1"));
		n1.addNews(News("Novina2"));
 
 
		NewsSite n2 = n1;
 
		n2.removeNews(0);

}

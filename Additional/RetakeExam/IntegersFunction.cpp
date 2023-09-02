#include <iostream>
#include <fstream>
#include <stdexcept>
#include <climits>

class IntegerFunction
{
public:
	virtual IntegerFunction* clone() const = 0;
	virtual int eval(int) const = 0;
	virtual ~IntegerFunction() = default;

};

template <typename T>
class ConcreteFunction : public IntegerFunction
{
    T criteria;
public:
	ConcreteFunction(const T& cr);
	ConcreteFunction(T&& cr);
	IntegerFunction* clone() const override;
	int eval(int) const override;

};
template <typename T>
ConcreteFunction<T>::ConcreteFunction(const T& cr) : criteria(cr)
{}

template <typename T>
ConcreteFunction<T>::ConcreteFunction(T&& cr) : criteria(std::move(cr))
{}

template <typename T>
IntegerFunction* ConcreteFunction<T>::clone() const {
	return new ConcreteFunction<T>(*this);
}

template <typename T>
int ConcreteFunction<T>::eval(int num) const
{
	return criteria(num);
}


class FuncOperation : public IntegerFunction
{
protected:
	IntegerFunction** sets;
	size_t count;
	void copyfrom(const FuncOperation& other);
	void free();
	void moveFrom(FuncOperation&& other);
public:
	FuncOperation(IntegerFunction** sets, size_t count);

	FuncOperation(const FuncOperation& other);
	FuncOperation& operator=(const FuncOperation& other);

	FuncOperation(FuncOperation&& other);
	FuncOperation& operator=(FuncOperation&& other);

	~FuncOperation();
	

};

void FuncOperation::copyfrom(const FuncOperation& other)
{
	sets = new IntegerFunction * [other.count];
	for (unsigned i = 0; i < other.count; i++)
		sets[i] = other.sets[i]->clone();

	count = other.count;
}
void FuncOperation::free()
{
	for (unsigned i = 0; i < count; i++)
		delete sets[i];
	delete[] sets;
}
void FuncOperation::moveFrom(FuncOperation&& other)
{
	sets = other.sets;
	count = other.count;

	other.sets = nullptr;
	other.count = 0;
}

FuncOperation::FuncOperation(IntegerFunction** sets, size_t count)
{
    this->count = count;
	this->sets = new IntegerFunction * [count];
	for (unsigned i = 0; i < count; i++)
		this->sets[i] = sets[i]->clone();
}

FuncOperation::FuncOperation(const FuncOperation& other) : IntegerFunction(other)
{
	copyfrom(other);
}
FuncOperation& FuncOperation::operator=(const FuncOperation& other)
{
	if (this != &other)
	{
	    IntegerFunction::operator=(other);
		free();
		copyfrom(other);
	}
	return *this;
}

FuncOperation::FuncOperation(FuncOperation&& other)
{
	moveFrom(std::move(other));
}

FuncOperation& FuncOperation::operator=(FuncOperation&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}


FuncOperation::~FuncOperation()
{
	free();
}



class MaxOfFunctions : public FuncOperation {
public:
	MaxOfFunctions(IntegerFunction** sets, size_t count);

	IntegerFunction* clone() const override;
	int eval(int) const override;
};

MaxOfFunctions::MaxOfFunctions(IntegerFunction** sets, size_t count) : FuncOperation(sets, count) {}

IntegerFunction* MaxOfFunctions::clone() const {
	return new MaxOfFunctions(*this);
}

int MaxOfFunctions::eval(int num) const
{
    int max = INT_MIN;
	for (unsigned i = 0; i < count; i++)
	{
	    int result = sets[i]->eval(num);
		if (result > max)
			max = result;
	}
	return max;
}


class MinOfFunctions : public FuncOperation {
public:
	MinOfFunctions(IntegerFunction** sets, size_t count);
	IntegerFunction* clone() const override;
	int eval(int) const override;
};


MinOfFunctions::MinOfFunctions(IntegerFunction** sets, size_t count) : FuncOperation(sets, count) {}

IntegerFunction* MinOfFunctions::clone() const {
	return new MinOfFunctions(*this);
}

int MinOfFunctions::eval(int num) const
{
    int min = INT_MAX;
	for (unsigned i = 0; i < count; i++)
	{
	    int result = sets[i]->eval(num);
		if (result < min)
			min = result;
	}
	return min;
}

struct BaseFunc
{
    const int* arr;
    size_t size;
    
    bool contains(int n) const
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == n)
                return true;
        }
        return false;
    }
    
    BaseFunc(const int* arr, size_t size): arr(arr), size(size){}
    
};

struct IdentityOrZeroFunc : BaseFunc
{
    IdentityOrZeroFunc(const int* arr, size_t size): BaseFunc(arr, size){}
    int operator()(int n) const
    {
        return contains(n) ? 0 : n;
    }
};

struct ZeroOrOneFunc : BaseFunc
{
    ZeroOrOneFunc(const int* arr, size_t size): BaseFunc(arr, size){}
    int operator()(int n) const
    {
        return contains(n) ? 1 : 0;
    }
};

void readFromFile(const char* fileName, int* arr, size_t& size)
{
    std::ifstream ifs(fileName);
    if(!ifs.is_open())
        return;

    while(!ifs.eof())
    {
        int current;
        ifs >> current;
            
        arr[size++] = current;
    }
}

int main() 
{
    const int MAX_SIZE = 10;
    int include[MAX_SIZE];
    size_t includeSize = 0;
    
    int exclude[MAX_SIZE];
    size_t excludeSize = 0;
    
    readFromFile("exclude.txt", exclude, excludeSize);
    readFromFile("include.txt", include, includeSize);
    
    IdentityOrZeroFunc cr1(exclude, excludeSize);
    ZeroOrOneFunc cr2(include, includeSize);
    
    ConcreteFunction<IdentityOrZeroFunc> f1(cr1);
    ConcreteFunction<ZeroOrOneFunc> f2(cr2);
    
    IntegerFunction* arr[2];
    arr[0] = &f1;
    arr[1] = &f2;
    
    MaxOfFunctions f3(arr, 2);
    
    for(int i = 0; i < 10; i++)
        std::cout << "f1(" << i << ")" << f1.eval(i) << " ";
    std::cout << std::endl;
    
      for(int i = 0; i < 10; i++)
        std::cout << "f2(" << i << ")" << f2.eval(i) << " ";
    std::cout << std::endl;
    
      for(int i = 0; i < 10; i++)
        std::cout << "f3(" << i << ")" << f3.eval(i) << " ";
    std::cout << std::endl;
    
}

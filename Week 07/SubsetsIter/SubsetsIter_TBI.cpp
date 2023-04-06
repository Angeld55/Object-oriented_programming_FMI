
class SubsetIterator
{
	bool* _currentSubset;
	const int* _arr;
	size_t _size;

public:
	SubsetIterator(const int* arr, size_t size) : _arr(arr), _size(size)
	{
		_currentSubset = new bool[size]{ 0 };
	}

	void gotToNextSubset()
	{
		int i = _size - 1;
		for (; i >= 0; i--)
		 
			if (_currentSubset[i] == 1)
				_currentSubset[i] = 0;
			else
				break;
		}
		if (i >= 0)
			_currentSubset[i] = 1;
	}
};

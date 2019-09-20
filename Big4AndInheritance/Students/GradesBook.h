class GradesBook
{
	int* grades;
	int size;
	int capacity;
	
	bool isValidGrade(int grade);
	void Resize();
	void CopyFrom(const GradesBook& other);
	void Free();
public:
	GradesBook();
	GradesBook(const GradesBook& other);
	GradesBook& operator=(const GradesBook& other);
	~GradesBook();
	
	bool isFull();
	void AddGrade(int grade);
	void RemoveLastGrade();
	
	int operator[](int index) const;
	friend ostream& operator<<(ostream& stream, GradesBook& obj);

};

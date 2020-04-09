#ifndef STRING_HDR
#define STRING_HDR

#include<iostream>
#include<fstream>

const int MAX_SIZE = 1024;

class String {

private:
	char* str;
	int len;

	void CopyFrom(const String& other);
	void Free();

public:
	String();
	String(char ch);
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	int getLenght() const;
	String SubString(int start);
	String SubString(int start, int end);
	int IndexOf(const String& other, int index); //return the index of the first encounter of other in the object
	int IndexOf(const char* str, int index); //reusing IndexOf(const String& other, int index)
	int CountOcurences(String str); // How many times a string is found as substring
	int GetOcurence(String str, int i); //Get if the i-th substring (count start from 1)

	const char& operator[](int index) const;
	char& operator[](int index);
	String& operator+=(const String& other); //return the concatenation of the object with other
	friend bool operator==(const String& lhs, const String& rhs); //return true if two strings are equivalent
	friend bool operator!=(const String& lhs, const String& rhs); //return true if two strings are not equivalent 
	friend std::ostream& operator<<(std::ostream& os, const String& obj);
	friend std::istream& operator>>(std::istream& is, String& obj);

	String* Split(String str);
};
const String operator+(const String& lhs, const String& rhs);
#endif // !STRING_HDR
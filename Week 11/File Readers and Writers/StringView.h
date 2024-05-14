#pragma once
#include <fstream>
#include "MyString.h"
class StringView
{
	const char* _begin = nullptr;
	const char* _end = nullptr; //1 element after the final char;

public:
	StringView() = default;
	StringView(const char* begin, const char* end);
	StringView(const char* str); //terminatedString
	StringView(const MyString& string);

	size_t length() const;
	char operator[](size_t ind) const;

	StringView substr(size_t from, size_t length) const;
	friend std::ostream& operator<<(std::ostream&, const StringView& strView);
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);

#pragma once
#pragma once
#include <iostream>
#include "StringPool.h"

class ImmutableString
{
	const char* _data;
	size_t _length;

	void copyFrom(const ImmutableString& data);
	void free();

	explicit ImmutableString(size_t capacity); 
	static StringPool _pool;

public:

	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	~ImmutableString();


	size_t length() const;

	char operator[](size_t index) const;

	const char* c_str() const;
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
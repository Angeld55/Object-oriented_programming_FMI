#include "StringView.h"

StringView::StringView(const char* begin, const char* end): _begin(begin), _end(end)
{}

StringView::StringView(const char* str) : StringView(str, str + strlen(str)) {}

StringView::StringView(const MyString& str) : StringView(str.c_str()) {}

size_t StringView::length() const
{
	return _end - _begin;
}
char StringView::operator[](size_t index) const
{
	return _begin[index];
}

StringView StringView::substr(size_t from, size_t length) const
{
	if (_begin + from + length > _end)
		throw std::length_error("Error, Substr out of range");

	return StringView(_begin + from, _begin + from + length);
}

std::ostream& operator<<(std::ostream& os, const StringView& strView)
{
	const char* iter = strView._begin;

	while (iter != strView._end)
	{
		os << *iter;
		iter++;
	}
	return os;
}

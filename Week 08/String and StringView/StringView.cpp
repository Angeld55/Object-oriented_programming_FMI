#include "StringView.h"

StringView::StringView(const char* begin, const char* end): _begin(begin), _end(end)
{}

StringView::StringView(const char* str) : StringView(str, str + strlen(str)) {}

StringView::StringView(const MyString& str) : StringView(str.c_str()) {}

size_t StringView::length()
{
	return _end - _begin;
}
char StringView::operator[](size_t ind) const
{
	return _begin[ind];
}

StringView StringView::substr(size_t from, size_t howMany)
{
	return StringView(_begin + from, _begin + from + howMany);
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
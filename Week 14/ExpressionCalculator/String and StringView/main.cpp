#include "StringView.h"

int main()
{
	MyString test = "Hi, petur!";
	StringView res(test);
	StringView res2 = res.substr(4, 5);
	std::cout << res2[0];
}

#include "Matcher.h"
bool TimesMatcher::match(int num)
{
	return num%base == 0;
}

bool ContainsMatcher::match(int num)
{
	string number = to_string(num);
	return number.find(to_string(base))!=string::npos;

}

bool Always::match(int num)
{
	return true;
}

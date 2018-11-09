#include "Matcher.h"
bool Times_Ni::match(int InNum)
{
	return InNum%base == 0;
}

bool Contains_Ni::match(int InNum)
{
	string Num = to_string(InNum);
	return Num.find(to_string(base))!=string::npos;

}

bool Always::match(int InNum)
{
	return true;
}

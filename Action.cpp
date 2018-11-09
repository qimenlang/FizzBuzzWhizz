#include "Action.h"

string SpecialNumAction::excute(int InNum)
{
	return BaseStr;
}

string DefaultAction::excute(int InNum)
{
	return to_string(InNum);
}

#include "Action.h"

string SpecialNumAction::excute(int num)
{
	return base;
}

string DefaultAction::excute(int num)
{
	return to_string(num);
}

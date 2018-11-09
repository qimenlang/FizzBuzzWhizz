#include "Rule.h"

string Atom::Apply(int Num)
{
	if (AtomMatcher->match(Num))
		return AtomAction->excute(Num);
	return "";
}

string AllOf::Apply(int Num)
{
	string Result;
	for (auto Rule:Rules)
	{
		Result.append(Rule->Apply(Num));
	}
	return Result;
}

string AnyOf::Apply(int Num)
{
	string Result;
	for (Rule* RulePtr : Rules)
	{
		Result = RulePtr->Apply(Num);
		if (Result.size() > 0) break;
	}
	return Result;
}

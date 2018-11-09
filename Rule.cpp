#include "Rule.h"

string Atom::Apply(int Num)
{
	string Result;
	if (AtomMatcher->match(Num))
		return AtomAction->excute(Num);
	return Result;
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
	string TempResult;
	for (Rule* RulePtr : Rules)
	{
		TempResult = RulePtr->Apply(Num);
		if (TempResult.size() > 0)
		{
			Result = TempResult;
			TempResult.clear();
			break;
		}
	}
	return Result;
}

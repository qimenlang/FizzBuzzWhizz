#include "Rule.h"

string Atom::Apply(int num)
{
	if (AtomMatcher->match(num))
		return AtomAction->excute(num);
	return "";
}

string AllOf::Apply(int num)
{
	string Result;
	for (auto Rule:rules)
	{
		Result.append(Rule->Apply(num));
	}
	return Result;
}

string AnyOf::Apply(int num)
{
	string Result;
	for (auto RulePtr : rules)
	{
		Result = RulePtr->Apply(num);
		if (Result.size() > 0) break;
	}
	return Result;
}

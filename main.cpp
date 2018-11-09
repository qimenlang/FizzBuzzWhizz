#include<iostream>
#include"Action.h"
#include"Matcher.h"
#include"Rule.h"
using namespace std;

int main()
{
	Matcher* matcher_always = new Always();
	Action* action_default = new DefaultAction();

	Matcher* matcher_times_3 = new TimesMatcher(3);
	Matcher* matcher_times_5 = new TimesMatcher(5);
	Matcher* matcher_times_7 = new TimesMatcher(7);

	Matcher* matcher_contains_3 = new ContainsMatcher(3);

	Action* action_special_num_fizz = new SpecialNumAction("Fizz");
	Action* action_special_num_buzz = new SpecialNumAction("Buzz");
	Action* action_special_num_whizz = new SpecialNumAction("Whizz");

	//TODO:Code Besides Should Be Refactor To DSL
	Rule* r1n1 = new Atom(matcher_times_3, action_special_num_fizz);
	Rule* r1n2 = new Atom(matcher_times_5, action_special_num_buzz);
	Rule* r1n3 = new Atom(matcher_times_7, action_special_num_whizz);

	Rule* r1 = new AllOf({ r1n1, r1n2, r1n3 });
	Rule* r2n1 = new Atom(matcher_contains_3, action_special_num_fizz);
	Rule* r3 = new Atom(matcher_always, action_default);

	Rule* ri = new AnyOf({ r2n1, r1, r3 });

	//TODO:Should Use Test FrameWork
	for (int i = 1; i <= 100; i++)
	{
		cout << ri->Apply(i) << endl;
	}
	getchar();
	return 0;
}
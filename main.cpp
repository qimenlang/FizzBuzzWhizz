#include<iostream>
#include"Action.h"
#include"Matcher.h"
#include"Rule.h"
using namespace std;

int main()
{
	/*
	r1n1=Times_ni,3->Special_Action(3)->Fizz
	r2n2=Times_ni,5->Special_Action(5)->Buzz
	r3n3=Times_ni,7->Special_Action(7)->Whizz
	r1=Allof(r1n1,r2n2,r3n3)
	r2=Contains_ni,3->Special_Action(3)->Fizz
	r3=NoMatch,NoAction

	Matcher
	Times_ni
	Contains_ni
	NoMatcher
	Actor
	Special_Action(3)->Fizz
	Special_Action(5)->Buzz
	Special_Action(7)->Whizz
	NoAction
	Rule
	Actom
	AllOf
	AnyOf

	AnyOf(r2,r1,r3)
	AnyOf(r2,AllOf(r1n1,r2n2,r3n3),r3)
	*/

	Matcher* Matcher_Times_3 = new Times_Ni(3);
	Matcher* Matcher_Times_5 = new Times_Ni(5);
	Matcher* Matcher_Times_7 = new Times_Ni(7);

	Action* Action_SpecialNum_Fizz = new SpecialNumAction("Fizz");
	Action* Action_SpecialNum_Buzz = new SpecialNumAction("Buzz");
	Action* Action_SpecialNum_Whizz = new SpecialNumAction("Whizz");

	Rule* r1n1 = new Atom(Matcher_Times_3, Action_SpecialNum_Fizz);
	Rule* r1n2 = new Atom(Matcher_Times_5, Action_SpecialNum_Buzz);
	Rule* r1n3 = new Atom(Matcher_Times_7, Action_SpecialNum_Whizz);

	vector<Rule*> Rule_All;
	Rule_All.push_back(r1n1);
	Rule_All.push_back(r1n2);
	Rule_All.push_back(r1n3);

	Rule* r1 = new AllOf(Rule_All);

	Matcher* Matcher_Contains_3 = new Contains_Ni(3);
	Rule* r2n1 = new Atom(Matcher_Contains_3, Action_SpecialNum_Fizz);

	Matcher* Matcher_Always = new Always();
	Action* Action_Default = new DefaultAction();
	Rule* r3 = new Atom(Matcher_Always, Action_Default);

	vector<Rule*> Rule_Any;//在Any中体现匹配的优先级
	Rule_Any.push_back(r2n1);
	Rule_Any.push_back(r1);
	Rule_Any.push_back(r3);
	Rule* ri = new AnyOf(Rule_Any);

	//TEST
	for (int i = 1; i <= 100; i++)
	{
		cout << ri->Apply(i) << endl;
	}
	getchar();
	return 0;
}
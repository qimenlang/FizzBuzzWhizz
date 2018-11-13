#include<iostream>
#include"gtest\gtest.h"
#include"assert.h"
#include"Action.h"
#include"Matcher.h"
#include"Rule.h"
using namespace std;

class RuleTest:public testing::Test
{
protected:
	Matcher* matcher_always;
	Action* action_default;

	Matcher* matcher_times_3;
	Matcher* matcher_times_5;
	Matcher* matcher_times_7;

	Matcher* matcher_contains_3;

	Action* action_special_num_fizz;
	Action* action_special_num_buzz;
	Action* action_special_num_whizz;

	Rule* r1n1;
	Rule* r1n2;
	Rule* r1n3;

	Rule* r1;
	Rule* r2n1;
	Rule* r3;
	Rule* rule;
	virtual void SetUp()
	{
		matcher_always = new Always();
		action_default = new DefaultAction();

		matcher_times_3 = new TimesMatcher(3);
		matcher_times_5 = new TimesMatcher(5);
		matcher_times_7 = new TimesMatcher(7);

		matcher_contains_3 = new ContainsMatcher(3);

		action_special_num_fizz = new SpecialNumAction("Fizz");
		action_special_num_buzz = new SpecialNumAction("Buzz");
		action_special_num_whizz = new SpecialNumAction("Whizz");

		//TODO:Code Besides Should Be Refactor To DSL
		r1n1 = new Atom(matcher_times_3, action_special_num_fizz);
		r1n2 = new Atom(matcher_times_5, action_special_num_buzz);
		r1n3 = new Atom(matcher_times_7, action_special_num_whizz);

		r1 = new AllOf({ r1n1, r1n2, r1n3 });
		r2n1 = new Atom(matcher_contains_3, action_special_num_fizz);
		r3 = new Atom(matcher_always, action_default);
		rule = new AnyOf({ r2n1, r1, r3 });
	}
	virtual void TearDown()
	{
		delete matcher_always;
		delete action_default;
		delete matcher_times_3;
		delete matcher_times_5;
		delete matcher_times_7;
		delete matcher_contains_3;
		delete action_special_num_fizz;
		delete action_special_num_buzz;
		delete action_special_num_whizz;
		delete r1n1;
		delete r1n2;
		delete r1n3;
		delete r1;
		delete r2n1;
		delete r3;
		delete rule;
	}

};

TEST_F(RuleTest,case1)
{
	EXPECT_EQ(rule->Apply(3), "Fizz");
	EXPECT_EQ(rule->Apply(5), "Buzz");
	EXPECT_EQ(rule->Apply(7), "Whizz");
	EXPECT_EQ(rule->Apply(3 * 5), "FizzBuzz");
	EXPECT_EQ(rule->Apply(5 * 7), "Fizz");
	EXPECT_EQ(rule->Apply(3 * 7), "FizzWhizz");
	EXPECT_EQ(rule->Apply(3 * 5 * 7), "FizzBuzzWhizz");
	EXPECT_EQ(rule->Apply(123), "Fizz");
	EXPECT_EQ(rule->Apply(1), "1");
	EXPECT_EQ(rule->Apply(1004), "1004");
}

int main(int argc,char* argv[])
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
	//test(ri);
	
	for (int i = 1; i <= 100; i++)
	{
		cout << ri->Apply(i) << endl;
	}

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}
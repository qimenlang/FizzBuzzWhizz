#include<iostream>
#include<memory>
#include"gtest\gtest.h"
#include"assert.h"
#include"Action.h"
#include"Matcher.h"
#include"Rule.h"
using namespace std;

class Game
{
public:
	Game(int num1, int num2, int num3)
	{
		shared_ptr<Matcher> matcher_always (new Always());
		shared_ptr<Action> action_default(new DefaultAction());

		shared_ptr<Matcher> matcher_times_1(new TimesMatcher(num1));
		shared_ptr<Matcher> matcher_times_2(new TimesMatcher(num2));
		shared_ptr<Matcher> matcher_times_3(new TimesMatcher(num3));

		shared_ptr<Matcher> matcher_contains_1(new ContainsMatcher(num1));

		shared_ptr<Action> action_special_num_fizz(new SpecialNumAction("Fizz"));
		shared_ptr<Action> action_special_num_buzz(new SpecialNumAction("Buzz"));
		shared_ptr<Action> action_special_num_whizz(new SpecialNumAction("Whizz"));

		//TODO:Code Besides Should Be Refactor To DSL
		shared_ptr<Rule> r1n1(new Atom(matcher_times_1, action_special_num_fizz));
		shared_ptr<Rule> r1n2(new Atom(matcher_times_2, action_special_num_buzz));
		shared_ptr<Rule> r1n3(new Atom(matcher_times_3, action_special_num_whizz));

		shared_ptr<Rule> r1(new AllOf({ r1n1, r1n2, r1n3 }));
		shared_ptr<Rule> r2n1(new Atom(matcher_contains_1, action_special_num_fizz));
		shared_ptr<Rule> r3(new Atom(matcher_always, action_default));
		rule = shared_ptr<Rule>(new AnyOf({ r2n1, r1, r3}));
	}
	~Game() {};
	string play(int num) 
	{
		return rule->Apply(num);
	}

private:
	shared_ptr<Rule>rule;
};

class RuleTest:public testing::Test
{
protected:
	Game* FizzGame;

	virtual void SetUp()
	{
		FizzGame = new Game(3, 5, 7);
	}
	virtual void TearDown()
	{
		delete FizzGame;
	}
	void rule(int num, const string& expect)
	{
		EXPECT_EQ(FizzGame->play(num), expect);
	}
};

TEST_F(RuleTest,case1)
{
	rule(3, "Fizz");
	rule(5, "Buzz");
	rule(7, "Whizz");
	rule(3 * 5, "FizzBuzz");
	rule(5 * 7, "Fizz");
	rule(3 * 7, "FizzWhizz");
	rule(3 * 5 * 7, "FizzBuzzWhizz");
	rule(123, "Fizz");
	rule(1, "1");
	rule(1004, "1004");
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	Game* fizz_game = new Game(2, 5, 11);
	for (int i = 1; i <= 100; i++)
	{
		cout << fizz_game->play(i) << endl;
	}
	getchar();
	return 0;
}
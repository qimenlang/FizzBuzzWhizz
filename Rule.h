#pragma once
#include"Matcher.h"
#include "Action.h"
#include<string>
#include<vector>
using namespace std;
class Rule
{
public:	
	virtual ~Rule() {};
	virtual  string Apply(int Num) = 0;

};

class Atom:public Rule
{
public:
	Atom(Matcher* InMatcher, Action* InAction):AtomMatcher(InMatcher),AtomAction(InAction) {};
	~Atom() {};
	virtual  string Apply(int Num) override;
private:
	Matcher* AtomMatcher;
	Action* AtomAction;
};

class AllOf:public Rule
{
public:
	AllOf(vector<Rule*>& InRules) :Rules(InRules) {};
	~AllOf() {};
	virtual  string Apply(int Num) override;
private:
	vector<Rule*> Rules;
};

class AnyOf :public Rule
{
public:
	AnyOf(vector<Rule*>& InRules) :Rules(InRules) {};
	~AnyOf() {};
	virtual  string Apply(int Num) override;
private:
	vector<Rule*> Rules;
};
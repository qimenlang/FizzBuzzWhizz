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
	virtual  string Apply(int num) = 0;

};

class Atom:public Rule
{
public:
	Atom(Matcher* InMatcher, Action* InAction):AtomMatcher(InMatcher),AtomAction(InAction) {};
	~Atom() {};
	virtual  string Apply(int num) override;
private:
	Matcher* AtomMatcher;
	Action* AtomAction;
};

class AllOf:public Rule
{
public:
	AllOf(vector<Rule*>&& rules) :rules(rules) {};
	~AllOf() {};
	virtual  string Apply(int num) override;
private:
	vector<Rule*> rules;
};

class AnyOf :public Rule
{
public:
	AnyOf(vector<Rule*>&& rules) :rules(rules) {};
	~AnyOf() {};
	virtual  string Apply(int num) override;
private:
	vector<Rule*> rules;
};
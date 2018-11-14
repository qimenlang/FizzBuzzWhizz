#pragma once
#include<iostream>
#include"Matcher.h"
#include "Action.h"
#include<string>
#include<vector>
#include<memory>
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
	Atom(shared_ptr<Matcher> InMatcher, shared_ptr<Action> InAction):AtomMatcher(InMatcher),AtomAction(InAction) {};
	~Atom() { cout << "~Atom()" << endl; };
	virtual  string Apply(int num) override;
private:
	shared_ptr<Matcher>AtomMatcher;
	shared_ptr<Action>AtomAction;
};

class AllOf:public Rule
{
public:
	AllOf(vector<shared_ptr<Rule>>&& rules) :rules(rules) {};
	~AllOf() { cout << "~AllOf()" << endl; };
	virtual  string Apply(int num) override;
private:
	vector<shared_ptr<Rule>> rules;
};

class AnyOf :public Rule
{
public:
	AnyOf(vector<shared_ptr<Rule>>&& rules) :rules(rules) {};
	~AnyOf() { cout << "~AnyOf()" << endl; };
	virtual  string Apply(int num) override;
private:
	vector<shared_ptr<Rule>> rules;
};
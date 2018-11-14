#pragma once
#include <string>
#include<iostream>
#include<memory>
using namespace std;
class Action
{
public:
	virtual ~Action() {};
	virtual string excute(int num) = 0;
};

class SpecialNumAction :public Action
{
public:
	SpecialNumAction(const string& str):base(str){}
	~SpecialNumAction() { cout << "~SpecialNumAction()" << endl; };
	virtual string excute(int num) override;
private:
	string base;
};

class DefaultAction :public Action
{
public:
	DefaultAction() {};
	~DefaultAction() { cout << "~DefaultAction()" << endl; };
	virtual string excute(int num) override;
};
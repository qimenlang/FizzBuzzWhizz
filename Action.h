#pragma once
#include <string>
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
	~SpecialNumAction() {};
	virtual string excute(int num) override;
private:
	string base;
};

class DefaultAction :public Action
{
public:
	DefaultAction() {};
	~DefaultAction() {};
	virtual string excute(int num) override;
};
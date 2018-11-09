#pragma once
#include <string>
using namespace std;
class Action
{
public:
	virtual ~Action() {};
	virtual string excute(int InNum) = 0;
};

class SpecialNumAction :public Action
{
public:
	SpecialNumAction(const string& InStr):BaseStr(InStr){}
	~SpecialNumAction() {};
	virtual string excute(int InNum) override;
private:
	string BaseStr;
};

class DefaultAction :public Action
{
public:
	DefaultAction() {};
	~DefaultAction() {};
	virtual string excute(int InNum) override;
};
#pragma once
#include<string>
using namespace std;
class Matcher
{
public:
	virtual ~Matcher() {};
	virtual bool match(int num) = 0;
private:
};
class TimesMatcher:public Matcher
{
public:
	TimesMatcher(int base):base(base) {};
	~TimesMatcher() {};
	virtual bool match(int num) override;
private:
	int base;
};

class ContainsMatcher :public Matcher
{
public:
	ContainsMatcher(int base) :base(base) {};
	~ContainsMatcher() {};
	virtual bool match(int num) override;
private:
	int base;
};

class Always:public Matcher
{
public:
	~Always(){};
	virtual bool match(int num) override; 
};
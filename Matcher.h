#pragma once
#include<string>
using namespace std;
class Matcher
{
public:
	virtual ~Matcher() {};
	virtual bool match(int InNum) = 0;
private:
};
class Times_Ni:public Matcher
{
public:
	Times_Ni(int InBase):base(InBase) {};
	~Times_Ni() {};
	virtual bool match(int InNum) override;
private:
	int base;
};

class Contains_Ni :public Matcher
{
public:
	Contains_Ni(int InBase) :base(InBase) {};
	~Contains_Ni() {};
	virtual bool match(int InNum) override;
private:
	int base;
};

class Always:public Matcher
{
public:
	~Always(){};
	virtual bool match(int InNum) override; 
};
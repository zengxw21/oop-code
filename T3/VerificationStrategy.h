#pragma once
# include <string>
using namespace std;
class VerificationStrategy
{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy:public VerificationStrategy{
public:
	string verify(string mes){
		string tmp;
		for (int i = 0; i <= 2;i++){
			tmp += mes[i];
		}
		return tmp;
	}
};

class IntervalStrategy:public VerificationStrategy{
public:
	string verify(string mes){
		string tmp;
		for (int i = 0; i < (int)mes.length();i+=2){
			tmp += mes[i];
		}
		return tmp;
	}
};

#pragma once
#include <string>

class PayStrategy {	
public:							
	virtual double pay(std::string name, double money) = 0;
};


class NormalStrategy : public PayStrategy {	
public:
	double pay(std::string name,double money){
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	double pay(std::string name,double money){
		if(money <= 10000.0){
			return money - 10.0;
		}
		else{
			double minus = std::min(20.0,money/1000.0);
			return money - minus;
		}
	}
};

class BitcoinStrategy : public PayStrategy {	
	double pay(std::string name,double money){
		double tmp = (double)name.length()*1.0 + 8.0;
		double minus = tmp*0.01;
		return money - minus;
	}
};

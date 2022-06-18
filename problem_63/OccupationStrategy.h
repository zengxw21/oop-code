#pragma once

class OccupationStrategy {	
public:							
	virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {
public:
	
	double getSalary(double base,double bonus,double level){
		if(level < 60.00){
			return base;
		}
		else if(level < 70.00 && level >= 60.00 ){
			return base + 0.60 * bonus;
		}
		else if(level >= 70.00 && level <80.00){
			return base + 0.70 * bonus;
		}
		else 
			return base + bonus;
	}
};

class DeveloperStrategy : public OccupationStrategy {	
public:
	double getSalary(double base,double bonus,double level){
		return base + bonus/100 *level;
	}
};
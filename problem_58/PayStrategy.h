#pragma once

class PayStrategy {
public:
    virtual float getpay(float) = 0;								
};


class NormalStrategy : public PayStrategy {
public:
    virtual float getpay(float money){
        return money;
    }
};

class RebateStrategy : public PayStrategy {	
public:
    virtual float getpay(float money){
        
        return money * 0.38;
    }
};

class ReturnStrategy : public PayStrategy {	
public:
    virtual float getpay(float money){
        return money >= 25 ? money - 10 : money; 
    }
};

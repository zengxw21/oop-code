#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {								
public:
    OccupationStrategy* ospt;
    PayStrategy* pspt;
    Calculator(OccupationStrategy* os,PayStrategy* ps ){
        //ospt = std::move(os);
        //pspt = std::move(ps);
        ospt = os;
        pspt = ps;
    }
    double getSalary(double base,double bonus,double level){
       return (*ospt).getSalary(base,bonus,level);
    }
    double pay(std::string name,double salary){
        return (*pspt).pay(name,salary);
    }
    ~Calculator(){
        delete ospt;
        delete pspt;
        ospt = nullptr;
        pspt = nullptr;
    }//虽然说不用删除也能ac，但是还是规范化吧。。。
};
//calculator为公用的接口。遇到的卡壳地方：不允许使用抽象类成员变量。解决办法：
//使用抽象类指针。
#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator {								
public:
    LoadStrategy* ls;
    PayStrategy* ps;
    Calculator(LoadStrategy* l, PayStrategy* p){
        ls = l;
        ps = p;
        l = nullptr;
        p = nullptr;
    }
    float load(){
        return ls->getload();
    }
    float pay(float money){
        return ps->getpay(money);
    }
};
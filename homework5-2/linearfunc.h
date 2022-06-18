#pragma once

#include "func.h"

class LinearFunc : public Func{
private:
    double fst,sec;
public:
    LinearFunc(double a, double b):fst(a),sec(b){}
    double getPoint(double point){
        return fst*point+sec;
    }
    
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个一次函数类
    // f(x) = ax + b;
};
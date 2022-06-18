#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    double fst,sec;
    Func *fst_fun;
    Func *sec_fun;
    // Todo
    // 声明成员变量
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2){
        fst = coe_1;sec = coe_2;
        fst_fun = fun_1; fun_1 = nullptr;
        sec_fun = fun_2; fun_2 = nullptr; 
    }
    double getPoint(double point){
        return fst * fst_fun->getPoint(point) + sec * sec_fun->getPoint(point);
    }
    ~CombFunc(){
        if(fst_fun){
            delete fst_fun;
            fst_fun=nullptr;
        }
        if(sec_fun){
            delete sec_fun;
            sec_fun=nullptr;
        }
    }
    // compute a * f(point) + b * g(point)
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个组合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构

    //貌似不需要向下类型转换，就会自动调用派生类的函数，有可能是因为在基类中
    //这个函数已经被声明为纯虚函数
    //另一种想法：纯虚函数也属于虚函数，运行时根据实际类型调用
};
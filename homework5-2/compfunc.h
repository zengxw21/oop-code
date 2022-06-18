#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    Func *outer_func;
    Func *inner_func;
    // Todo
    // 声明成员变量
public:
    CompFunc(Func *outer, Func* inner){
        outer_func = outer; outer = nullptr;
        inner_func = inner; inner = nullptr;
    }
    double getPoint(double point){
        return outer_func->getPoint(inner_func->getPoint(point));
    }
    ~CompFunc(){
        if(outer_func){
            delete outer_func;
            outer_func=nullptr;
        }
        if(inner_func){
            delete inner_func;
            inner_func=nullptr;
        }
    }
    // compute f(g(x))
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个复合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构

    //注意，使用“移动思想”来对成员指针赋值很好，但是析构函数必须实现对内存的管理，
    //也就是说手动删除申请的内存。注意，delete和指针置空应当配套，避免野指针。
};
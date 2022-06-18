#pragma once

#include <cmath>

class Func{
public:
    Func() {}
    virtual double getPoint(double point)=0;
    virtual ~Func(){}// Todo 补充完整Func类,防止在析构时子类出现内存泄露问题

    //注意，如果getpoint不设置为纯虚函数，就必须有定义来实现，但是这个函数要求有返回值
    //作为一个基类，这是办不到的，只能设为纯虚函数避免定义
    //“总是将基类析构函数设置为虚函数”
};


#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    int size();// TODO
    int& operator[](string s){//非常量对象调用
        //如果有这个值，直接返回
        for(int i=0;i<sz;i++){
            if(data[i].hasKey(s)){
                return data[i].getVal();
            }
        }
        //没有则添加
        data[sz].reset(s,0);
        sz++;
        return data[sz-1].getVal();
    }
    const int operator[](const string& s)const{
        
        for(int i=0;i<sz;i++){
            if(data[i].hasKey(s)){
                return data[i].getVal();
            }
        }
        const int zero=0;
        return zero;
    }
    ~Map();
};
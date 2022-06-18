#pragma once
#include<iostream>
#include "BaseTree.h"
using namespace std;
class MyTree: public BaseTree {
public:
    void add(int x,int t){
        update(x,t);
    }
    void sub(int x,int t){
        update(x,-t);
    }
    void query(int x,int t){
        cout<< getsum(t) - getsum(x-1)<<endl;;
    }
    void set(int x,int t){
        int a = getsum(x) - getsum(x-1);
        update(x,-a);
        update(x,t);
    }
    void mul(int x,int t){
        int a = getsum(x) - getsum(x-1);//the xth element of the array
        for(int i = 1; i < t; i ++){
            update(x,a);
        }
    }
};

#pragma once
#include"Cow.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Farm{
public:
    int num;
    double total_milk = 0;
    Farm(int n) { num = n; }
    vector<Cow> total;
    void addCow(Cow c){
        total.push_back(c);
    }
    void supply(string _name,int n){
        for(auto &i:total){
            if(i.name==_name){
                i.cur += n;
            }
        }
    }
    void startMeal(){
        for(auto &i:total){
            if(i.cur == 0){
                continue;
            }
            else if(i.cur > 0 && i.cur <i.lower){
                i.cur = 0;
                i.produce += 0.5 * i.milk;
            }
            else if(i.cur>=i.lower && i.cur<=i.upper){
                i.cur = 0;
                i.produce += i.milk;
            }
            else if(i.cur>i.upper){
                i.cur -= i.upper;
                i.produce += i.milk;
            }
        }
    }
    void produceMilk(){
        for(auto &i:total){
            total_milk += i.produce;
            i.produce = 0;
        }
    }
    double getMilkProduction(){
        return total_milk;
    }
};
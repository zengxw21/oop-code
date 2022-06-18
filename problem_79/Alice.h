#pragma once
#include"Part.h"
#include<iostream>
using namespace std;

class Alice:public Robot{
public:
    int total;
    int current = 0;
    Alice(int k):total(k){
        parts = new Part[k];
    }
    void add_part(Part p){
        parts[current] = p;
        current ++;
    }
    bool is_full(){
        return current == total;
    }
    int run(){
        int tmp = 0;
        for(int i = 0; i < total; i ++){
            tmp += parts[i].id;
        }
        return tmp;
    }
    friend ostream& operator<<(ostream& out,Alice & a);
    ~Alice(){
        delete[]parts;
    }
};

ostream& operator<<(ostream& out, Alice& a){
    out<<"Build robot Alice";
    return out;
}
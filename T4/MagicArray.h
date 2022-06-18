#pragma once
#include <iostream>
#include <vector>
#include "Instruction.h"
using namespace std;

class MagicArray;

class Return_Type{
public:
    vector<RealInstruction>* rins;
    int index;
    void operator+=(int x){ // a[i] += j 操作
        RealInstruction ins(index, x);
        rins->push_back(ins);
    }
    void operator+=(Return_Type& elem){ // a[i] += a[j] 操作
        RealInstruction ins(index, elem.index, 1);
        rins->push_back(ins);
    }
    void operator=(Return_Type& elem){ // a[i] = a[j] 操作
        RealInstruction ins(index, elem.index, 0);
        rins->push_back(ins);
    }
    friend Return_Type& operator<<(ostream& out, Return_Type& elem){ // cout << a[i] 操作
        RealInstruction ins(elem.index, 0, -1);
        elem.rins->push_back(ins);
        return elem;
    }
    friend void operator<<(Return_Type& elem, int x){ // cout << endl 操作
        RealInstruction ins(0, 0, -2);
        elem.rins->push_back(ins);
    }
};

class MagicArray{
private:
    vector<RealInstruction> Instructions;
    vector<Instruction*> back;
    Return_Type arr[100];
public:
    friend Return_Type;
    MagicArray(int x){
        for(int i = 0; i < x; i++){
            arr[i].index = i;
            arr[i].rins = &Instructions;
        }
    };
    Return_Type& operator[](int index){
        return arr[index];
    }
    int endl(){
        int x = 1;
        return x;
    }
    void apply(vector<int> &vec){
        for(auto& ins : Instructions)
            ins.apply(vec);
    };
    void apply(vector<double> &vec){
        for(auto& ins : Instructions)
            ins.apply(vec);
    };
    vector<Instruction*>& getInstructions(){
        for(int i = 0; i < Instructions.size(); i++)
            back.push_back(&Instructions[i]);
        return back;
    }
};
#pragma once
#include "operation.h"

class sub:public OperationNodeTwo{
public:
    sub(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){
        //calc();
    }
    void UpdateValue();
    ~sub(){}
};
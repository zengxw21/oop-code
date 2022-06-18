#pragma once
#include "operation.h"
class add:public OperationNodeTwo{
public:
    add(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){
        //calc();
    }
    void UpdateValue() ;
    ~add(){}
};
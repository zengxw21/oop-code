#pragma once

#include <string>

#include "Hash.h"

#include<iostream>
template <typename T1, typename T2>
class HashTable{
public:
    Hash<T1> member;
    
    int capacity;
    //T2* val[5005];
    T2 ** val;
    HashTable(int _n):member(_n){ 
        val=new T2*[_n];
        for(int i=0;i<_n;i++){
            val[i]=nullptr;
        }
        capacity=_n;    
    }
    ~HashTable(){
        for(int i=0;i<capacity;i++){
            if(val[i]!=nullptr){
                delete val[i];
                val[i]=nullptr;
            }
        }
        delete[]val;
    }
    void addItem(const T1 &key, const T2 &value){
        int index=member.operator()(key);
        if(val[index]!=nullptr){
            delete val[index];
            val[index]=nullptr;
        }
        val[index]=new T2(value);
        
    }
    void removeItem(const T1 &key){
        if(val[member.operator()(key)]){
            delete val[member(key)];
            val[member.operator()(key)] = nullptr;
        }
    }
    T2 *findByKey(const T1 &key){
        
        return val[member.operator()(key)];
    }
};
////////////////////////////////////////////////////////////
//   如果定义了一个副本T2数组，取对应的下标地址传给val，就会  //
//   出错，原因还不知道。                       2022.4.30  //
///////////////////////////////////////////////////////////
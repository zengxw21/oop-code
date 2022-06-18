#pragma once
#include "what.h"
#include<string>
using namespace std;

class Alien:public WhatCanMotion,public WhatCanSpeak{
public:
    string name;
    Alien(string _name){
        name = _name;
    }
    void speak(){
        cout<<name<<" is speaking"<<endl;
    }
    void stop(){
        cout<<name<<" stops"<<endl;
    }
    void motion(){
        cout<<name<<" is moving"<<endl;
    }
};
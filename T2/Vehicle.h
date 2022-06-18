#pragma once
#include<string>
using namespace std;

class Vehicle{
public:
    int total_wheel;
    int total_wing;
    void set_max_wheel_num(int i){
        total_wheel = i;
    }
    void set_max_wing_num(int i){
        total_wing = i;
    }
    int wheel = 0;
    int wing = 0;
    void add_wheel(){
        wheel ++;
    }
    void add_wing(){
        wing ++;
    }
    bool finished(){
        return wing == total_wing && wheel == total_wheel;

    }
    virtual void run(){
        cout << "I am running" << endl;
    }
};

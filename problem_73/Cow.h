#pragma once
#include<string>
using namespace std;

class Cow{
public:
    int lower, upper, milk;
    double produce = 0;
    int cur = 0;//食物
    string name;
    Cow(string _name, int l, int u, int m) : 
    lower(l), upper(u), milk(m), name(_name){};
};
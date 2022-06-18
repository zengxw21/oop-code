#pragma once
#include"Student.h"
#include<vector>

using namespace std;

vector<int> select(vector<int> credit,int l,int r,Student *student){
    vector<int> tmp;
    tmp = (*student).choose(credit,l,r);
    return tmp;
}
#pragma once
#include <vector>

using namespace std;

class Student{
public:
    virtual vector<int> choose( vector<int>  credit,int l,int r)=0;
};

class StudentTypeA: public Student{
public:
    vector<int> choose( vector<int>  credit,int l,int r){
        vector <int> tmp;
        for(auto it = l-1; it <= r-1; it++){
            if(credit[it] <= 2){
                tmp.push_back(it+1);
            }
        }
        return tmp;
    }
};

class StudentTypeB: public Student{
public:
    
    vector<int> choose( vector<int>  credit,int l,int r){
        vector<int> tmp;
        for(int i = l-1; i <= r-1; i ++){
            bool isprime = true;
            if(i+1 == 2|| i+1 == 3) isprime = true;
            else if(i+1 == 1) isprime = false;
            else{
                for(int j = 2; j*j <= i+1; j ++){
                    if((i+1) % j == 0){
                        isprime = false;
                    }
                }
            }
            if(isprime){
                tmp.push_back(i+1);
            }
        }
        return tmp;
    }
};

class StudentTypeC: public Student{
public:
    vector<int> choose( vector<int>  credit,int l,int r){
        vector<int> tmp;
        for(int i = l-1; i <= r-1; i ++){
            
            if((i+1) % credit[i] == 0){
                tmp.push_back(i+1);
            }
        }
        return tmp;
    }
};

//注意vector中的下标是从0开始，所以直接传入l和r会造成想要的数和实际的相差1。
//题目所说的l和r是从1开始的，要小心。

#pragma once
#include<sstream>
#include<map>

class LoadStrategy {
public:
    virtual float getload() = 0;
};
using namespace std;

class NumberLoadStrategy : public LoadStrategy {
public:
    float getload(){
        float tmp;
        cin >> tmp;
        return tmp;
    }
};

class WordLoadStrategy : public LoadStrategy {
public:
    float getload(){
        stringstream ss;
        string str;
        getline(cin,str);
        getline(cin,str,'#');
        ss << str;
        string cash[50];
        int index = 1;
        while(ss >> cash[index]){
            index ++;
        }
        map<string,int> word;
        string stringmoney;
        word["one"]=1;word["two"]=2;word["three"]=3;word["four"]=4;word["five"]=5;
        word["six"]=6;word["seven"]=7;word["eight"]=8;word["nine"]=9;
        for(int i = 1; i < index ; i ++){
            stringmoney += to_string(word[cash[i]]);
        }
        int ans = stoi(stringmoney);
        return ans;
    }
};

//经验：首先输入两个字符串以后，要换行才输入另一行，如果只调用一次getline的话，
//因为getline默认读到换行符为止，所以你一上来就输入换行符，他就会以为你已经输入完了
//因此遇到先换行再输入的要调用两次getline。
//此外，要想读到某个特定的字符为止，getline还提供了第三个参数。
//最大的问题是如何处理输入！

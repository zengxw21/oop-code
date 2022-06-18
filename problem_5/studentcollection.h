#pragma once
#include<student.h>
#include<string>
#include<vector>
using namespace std;

class StudentCollection{
public:
    vector<Student> stu;
    vector<string> namelist;
    friend istream& operator>>(istream& in,StudentCollection& sc);
    Student& operator[](string _name){
        for(auto& i : stu){
            if(i.name == _name){
                return i;
                break;
            }
        }
    }
};

istream& operator>>(istream& in,StudentCollection& sc){
    string tmp;
    in>>tmp;
    string info[3];
    int index = 0;
    for(int i = 0; i < (int)tmp.length(); i++){
        if(tmp[i]=='-'){
            index++;
        }
        else{
            info[index] += tmp[i];
        }
    }
    
    bool have = false;
    for(auto&i : sc.namelist){
        if(i == info[0]){
            have = true;
        }
    }
    if(have){
        if(info[1]=="Chinese"){
            sc[info[0]].chinese_score = stoi(info[2]) ;
        }
        if(info[1]=="Math"){
            sc[info[0]].math_score = stoi(info[2]);
        }
        if(info[1]=="English"){
            sc[info[0]].english_score = stoi(info[2]);
        }
    }
    else{
        Student s;
        if(info[1]=="Chinese"){
            s.chinese_score = stoi(info[2]);
        }
        if(info[1]=="Math"){
            s.math_score = stoi(info[2]);
        }
        if(info[1]=="English"){
            s.english_score = stoi(info[2]);
        }
        sc.stu.push_back(s);
    }
    sc.namelist.push_back(info[0]);
    return in;
}
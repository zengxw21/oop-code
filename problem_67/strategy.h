#pragma once
#include "message.h"
#include<vector>
using namespace std;
class Strategy {
public:
    virtual void sort (vector<Message>& stu_list) = 0;
};

void swap(Message& a,Message& b){
    Message tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

class FirstStrategy : public Strategy {	
public:
    void sort(vector<Message>& stu_list){
        for(int i = 0; i < (int)(stu_list.size() - 1); i ++){
            for(int j = 0; j < (int)(stu_list.size() - 1) - i; j ++){
                int a = stu_list[j].first_score();
                int b = stu_list[j+1].first_score();
                if(a < b){
                    swap(stu_list[j],stu_list[j+1]);
                }
                if(a == b){
                    int c = stu_list[j].id();
                    int d = stu_list[j+1].id();
                    if(c < d){
                        swap(stu_list[j],stu_list[j+1]);
                    }
                }
            }
        }
    }
};

class SecondStrategy : public Strategy {
public:
    void sort(vector<Message>& stu_list){
        for(int i = 0; i < (int)(stu_list.size() - 1); i ++){
            for(int j = 0; j < (int)(stu_list.size() - 1) - i; j ++){
                int a = stu_list[j].second_score();
                int b = stu_list[j+1].second_score();
                if(a < b){
                    swap(stu_list[j],stu_list[j+1]);
                }
                if(a == b){
                    int c = stu_list[j].id();
                    int d = stu_list[j+1].id();
                    if(c < d){
                        swap(stu_list[j],stu_list[j+1]);
                    }
                }
            }
        }
    }
};

class TotalStrategy : public Strategy {
public:
    void sort(vector<Message>& stu_list){
        for(int i = 0; i < (int)(stu_list.size() - 1); i ++){
            for(int j = 0; j < (int)(stu_list.size() - 1) - i; j ++){
                int a = stu_list[j].total_score();
                int b = stu_list[j+1].total_score();
                if(a < b){
                    swap(stu_list[j],stu_list[j+1]);
                }
                if(a == b){
                    int c = stu_list[j].id();
                    int d = stu_list[j+1].id();
                    if(c < d){
                        swap(stu_list[j],stu_list[j+1]);
                    }
                }
            }
        }
    }
};

class StudentidStrategy : public Strategy {
public:
    void sort(vector<Message>& stu_list){
        for(int i = 0; i < (int)(stu_list.size() - 1); i ++){
            for(int j = 0; j < (int)(stu_list.size() - 1) - i; j ++){
                int a = stu_list[j].id();
                int b = stu_list[j+1].id();
                if(a < b){
                    swap(stu_list[j],stu_list[j+1]);
                }
            }
        }
    }	
};//i 和 j 要分清楚！！
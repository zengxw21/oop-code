#include "Server.h"
#include"Task.h"
#include<string.h>
Server::Server(int N,int M){
    total=N;
    p=new int[N+1];
    for(int i=1;i<=N;i++){
        p[i]=M;
    }
}
 void Server::tick(){//记录时间流动以及将结束的任务所占用的显存归还
     server_time++;
     for(int k=1;k<=tmp;k++){
         if(server_time==current[k].start+current[k].last&&current[k].finish==false){
             //时间上刚好匹配且正在进行
             current[k].finish=true;
            for(int v=1;current[k].num[v]!=0;v++){//归还显存
                p[current[k].num[v]]+=current[k].vol;
            }
         }
     }
}
bool Server::submit_task(Task cur){
    int count=0;int col[total+1]={0};//col记录可以使用的显卡的号数
    for(int j=1;j<=total;j++){
        if(p[j]>=cur.m_){
            count++;
            col[count]=j;
        }
        if(count==cur.n_){
            for(int k=1;col[k]!=0&&k<=total;k++){
                p[col[k]]-=cur.m_;
            }
            tmp++;
            strcpy(current[tmp].name,cur.id);
            current[tmp].vol=cur.m_;
            current[tmp].last=cur.d_;
            current[tmp].start=server_time;
            current[tmp].finish=false;//代表任务开始
            for(int v=1;v<=count;v++){
                current[tmp].num[v]=col[v];//将任务上传到服务器
            }
            return true;
        }
    }
    return false;
}
bool Server::cancel_task(char s[30]){
    for(int k=1;k<=tmp;k++){
        if(strcmp(s,current[k].name)==0){
            if(current[k].finish==false){
                current[k].finish=true;//终止任务
                for(int v=1;current[k].num[v]!=0;v++){
                    p[current[k].num[v]]+=current[k].vol;
                }
                return true;
            }
            else
                return false;
        }
    }
    return false;//如果没找到同名任务，也就是任务不存在的情况
}

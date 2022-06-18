#pragma once
class Server{
public:
    Server(int,int);
    int *p;
    int total;
    void tick();
    bool submit_task(class Task);
    bool cancel_task(char s[30]);
    struct cur_task{
        int vol;//占用每块显卡的显存多少
        int num[101];//占用的显卡的号数
        char name[30];
        int last;//任务运行所需时间
        int start;//任务开始时刻
        bool finish=true;
    }current[201];
    int tmp=0;//记录当前第一个正在进行的任务编号,后改为任务总数
    int server_time=0;
};
#include "Task.h"
#include<string.h>
Task::Task(char s[30],int d,int n,int m){
    strcpy(id,s);
    d_=d;n_=n;m_=m;
}
#pragma once
#include <vector>
using namespace std;

class Instruction{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};

class RealInstruction : public Instruction{
private:
    int left; // 记录操作符号左端 a[i] 的 index 值 : i
    int right; // 记录操作符号右端 a[j] 的 index 值 : j, 若无则记-1
    int plus; // 记录操作 a[i] += j 的值 : j, 若无, 则用 plus 的值区分不同操作
public:
    RealInstruction(int l, int r, int p):left(l), right(r), plus(p){ }
    RealInstruction(int l, int p):left(l), right(-1), plus(p){ }
    void apply(std::vector<int> &vec){
        if(right == -1) // 筛选出 a[i] += j 操作
            vec[left] += plus;
        else if(plus == 0) // 筛选出 a[i] += a[j] 操作
            vec[left] = vec[right];
        else if(plus == 1) // 筛选出 a[i] = a[j] 操作
            vec[left] += vec[right];
        else if(plus == -1) // 筛选出 cout << a[i] 操作
            cout << vec[left];
        else if(plus == -2) // 筛选出 cout << endl 操作
            cout << endl;
    };
    void apply(std::vector<double> &vec){
        if(right == -1)
            vec[left] += plus;
        else if(plus == 0)
            vec[left] = vec[right];
        else if(plus == 1)
            vec[left] += vec[right];
        else if(plus == -1)
            cout << vec[left];
        else if(plus == -2)
            cout << endl;
    };
    void output(){
        if(right == -1)
            cout << "arr[" << left << "] += " << plus << endl;
        else if(plus == 0)
            cout << "arr[" << left << "] = " << "arr[" << right << "]" << endl;
        else if(plus == 1)
            cout << "arr[" << left << "] += " << "arr[" << right << "]" << endl;
        else if(plus == -1)
            cout << "cout << arr[" << left << "]" << endl;
        else if(plus == -2)
            cout << "cout << endl" << endl;
    };
};
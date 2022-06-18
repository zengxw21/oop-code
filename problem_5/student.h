#include<string>
using namespace std;

class Student{
public:
    int total;
    int chinese_score,math_score,english_score;
    string name;
    int getsum(){
        return chinese_score + math_score + english_score;
    }
    bool operator<(  Student& s2){
        int a=this->getsum();
        int b=s2.getsum();
        return a<b;
    }
    friend ostream& operator<<(ostream& out,Student & s){
        
    }
};
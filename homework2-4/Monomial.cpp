#include"Monomial.h"
#include<string>
using namespace std;
Monomial::Monomial(){

}
std::istream& operator>>(std::istream& in,Monomial& model){
    in>>model.mono;
    std::string s1;//系数
    std::string s2;//次数
    int i;
    for(i=0;model.mono[i]!='x';i++){
        s1+=model.mono[i];
    }
    i+=2;
    for(int j=i;j<model.mono.length();j++){
        s2+=model.mono[j];
    }
    const char*p1=s1.c_str();
    const char*p2=s2.c_str();
    model.coe=atoi(p1);
    model.deg=atoi(p2);
    return in;
}
 std::ostream& operator<<(std::ostream& out, Monomial& model){
    out<<model.mono<<std::endl;
    return out;
}//这里可能还要改

Monomial::Monomial(int _c, int _d){
    coe=_c;deg=_d;
    mono=std::to_string(coe)+"x^"+std::to_string(deg);
}//这里可能还要稍微改动


Monomial Monomial::operator+(const Monomial &x) const{
    if(coe+x.coe!=0){//如果系数不为0
        Monomial tmp(coe+x.coe,deg);
        return tmp;
    }
    Monomial tmp(0,0);//如果系数为0，次数也为0
    return tmp;
}
Monomial Monomial::operator-(const Monomial& x)const {
    if(coe-x.coe!=0){
    Monomial tmp(coe-x.coe,deg);
    return tmp;}
    Monomial tmp(0,0);
    return tmp;
}
Monomial Monomial::operator*(const Monomial& x)const{
    if(coe*x.coe!=0){
    Monomial tmp(coe*x.coe,deg+x.deg);
    return tmp;}
    Monomial tmp(0,0);
    return tmp;
}
Monomial Monomial::operator/(const Monomial& x)const {
    if(coe/x.coe!=0)
    {Monomial tmp(coe/x.coe,deg-x.deg);
    return tmp;}
    Monomial tmp(0,0);
    return tmp;
}
Monomial Monomial::derive() const{
    if(deg!=0){
    Monomial tmp(coe*deg,deg-1);
    return tmp;}
    else{
        Monomial tmp(0,0);
        return tmp;
    }
}
int Monomial::get_val(int x)const{
    if(deg>=1){
        int tmp=x;
        for(int i=1;i<deg;i++){
            tmp*=x;
        }
        return tmp*coe;
    }
    else if(deg==0){
        return coe;
    }
    else{
        int tmp=x;
        for(int i=1;i<0-deg;i++){
            tmp*=x;
        }
        return coe/tmp;
    }
    return 0;//防止编译器警告
}
int Monomial::definite_integral(const int a, const int b) const{
    int high=b;int low=a;
    int tmp;
    if(deg>=0){
        for(int i=1;i<deg+1;i++){
            high*=b;
            low*=a;
        }
    tmp=coe*(high-low)/(deg+1);
    }
    else{
        for(int i=1;i<0-(deg+1);i++){
            high*=b;
            low*=a;
        }
    tmp=coe/((deg+1)*high)-coe/((deg+1)*low);
    }
    return tmp;
}
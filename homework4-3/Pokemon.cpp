#include"Pokemon.h"
#include<string>
using namespace std;
Pokemon::Pokemon(int _hp,int _atk,string _name){
    tot_hp=_hp;
    hp=_hp;
    atk=_atk;
    name=_name;
}
string Pokemon::get_name(){
    return name;
}
bool Pokemon::alive(){
    if(hp<=0)return false;
    return true;
}
int Pokemon::get_hp(){
    return hp;
}
int Pokemon::get_atk(){
    return atk;
}
Pokemon::~Pokemon(){}

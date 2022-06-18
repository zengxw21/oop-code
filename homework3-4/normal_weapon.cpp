#include"normal_weapon.h"
#include"weapon.h"
#include<string>
#include<iostream>
using namespace std;
int NormalWeapon::num=0;
NormalWeapon::NormalWeapon(string name):Weapon(name){
        expand_name=name;
        cout<<"Normal weapon "<<name<<" was created."<<endl;
}
NormalWeapon::~NormalWeapon(){
        cout<<"Normal weapon "<<expand_name<<" was destroyed."<<endl;
    }
void NormalWeapon::up(int lv){
        upgrade();
        string new_expand_name=get_name()+"+"+to_string(lv);
        cout<<"Normal weapon "<<expand_name<<" was upgraded to "<<new_expand_name<<"."<<endl;
        expand_name=new_expand_name;
    }
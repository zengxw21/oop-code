#include"somber_weapon.h"
#include"weapon.h"
#include<string>
#include<iostream>
using namespace std;
int SomberWeapon::num=0;
SomberWeapon::SomberWeapon(string name):Weapon(name){
        expand_name=name;
        cout<<"Somber weapon "<<name<<" was created."<<endl;
    }
SomberWeapon::~SomberWeapon(){
        cout<<"Somber weapon "<<expand_name<<" was destroyed."<<endl;
    }
void SomberWeapon::up(int lv){
        upgrade();
        string new_expand_name=get_name()+"+"+to_string(lv);
        cout<<"Somber weapon "<<expand_name<<" was upgraded to "<<new_expand_name<<"."<<endl;
        expand_name=new_expand_name;
    }
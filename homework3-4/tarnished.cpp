#include "tarnished.h"
#include "normal_smithing_stone.h"
#include "normal_weapon.h"
#include "somber_smithing_stone.h"
#include "somber_weapon.h"
#include<iostream>
using namespace std;
Tarnished::Tarnished(){
    for(int i=0;i<MAX_STONES;i++){
        somber_smithing_stones[i]=nullptr;
        normal_smithing_stones[i]=nullptr;
    }
    for(int i=0;i<MAX_WEAPONS;i++){
        somber_weapons[i]=nullptr;
        normal_weapons[i]=nullptr;
    }
}
Tarnished::~Tarnished(){
    for(int i=0;i<MAX_STONES;i++){
        if(normal_smithing_stones[i]) delete normal_smithing_stones[i];
    }
    for(int i=0;i<MAX_STONES;i++){
        if(somber_smithing_stones[i])delete somber_smithing_stones[i];
    }
    for(int i=0;i<MAX_WEAPONS;i++){
        if(normal_weapons[i])delete normal_weapons[i];
    }
    for(int i=0;i<MAX_WEAPONS;i++){
        if(somber_weapons[i])delete somber_weapons[i];
    }
}
void Tarnished::pick_up_stone(int type,int level,int number){
    if(type==0){//if normal
        if(normal_smithing_stones[level]==nullptr) normal_smithing_stones[level]=new NormalSmithingStone(level);
        normal_smithing_stones[level]->echo(number);
    }
    if(type==1){//if somber
        if(somber_smithing_stones[level]==nullptr) somber_smithing_stones[level]=new SomberSmithingStone(level); 
        somber_smithing_stones[level]->echo(number);
    }
}
void Tarnished::pick_up_weapon(int type,string name){
    if(type==0){
        normal_weapons[NormalWeapon::num]=new NormalWeapon(name);
        NormalWeapon::num++;
    }
    if(type==1){
        somber_weapons[SomberWeapon::num]=new SomberWeapon(name);
        SomberWeapon::num++;
    }
}
void Tarnished::upgrade_weapon(int target,string name){
    bool have_weapon=false;

    for(int i=0;i<NormalWeapon::num;i++){
        if(normal_weapons[i]->get_name()==name){
            string initial_name=normal_weapons[i]->expand_name;
            have_weapon=true;
            if(target<=normal_weapons[i]->get_level()){
                cout<<"Stay calm!"<<endl;
                return;
            }
            int total_need[9]={0};
            for(int id=normal_weapons[i]->get_level();id<target;id++){//id是升级到下一级所需要的石头等级
                int stone_level=id/3+1;
                int add=2*(id%3)+2;
                total_need[stone_level]+=add;
            }
            for(int id=normal_weapons[i]->get_level();id<target;id++){
                if(normal_smithing_stones[id/3+1]==nullptr){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<id/3+1<<"."<<endl;
                    return;
                }
                if(normal_smithing_stones[id/3+1]->greater_equal(total_need[id/3+1])==false){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<id/3+1<<"."<<endl;
                    return;
                }
            }
            for(int id=normal_weapons[i]->get_level();id<target;id++){
                int current_need=2*(id%3)+2;
                int stone_level=id/3+1;
                int sub=0-current_need;
                normal_smithing_stones[stone_level]->substract(sub);

                if(normal_smithing_stones[stone_level]->greater_equal(1)==false){
                    delete normal_smithing_stones[stone_level];
                    normal_smithing_stones[stone_level]=nullptr;
                }
                normal_weapons[i]->up(id+1);
            }
            cout<<"Upgrade "<<initial_name<<" to "<<normal_weapons[i]->expand_name<<" Successfully."<<endl;
        }   
            
    }
    for(int i=0;i<SomberWeapon::num;i++){
        if(somber_weapons[i]->get_name()==name){
            have_weapon=true;
            string initial_name=somber_weapons[i]->expand_name;
            if(target<=somber_weapons[i]->get_level()){
                cout<<"Stay calm!"<<endl;
                return;
            }
            for(int j=somber_weapons[i]->get_level()+1;j<=target;j++){
                if(somber_smithing_stones[j]==nullptr){
                    cout<<"Upgrade failed for lacking somber smithing stone "<<j<<"."<<endl;
                    return;
                }
            }
            for(int j=somber_weapons[i]->get_level()+1;j<=target;j++){
                somber_smithing_stones[j]->substract(-1);

                if(somber_smithing_stones[j]->greater_equal(1)==false){
                    delete somber_smithing_stones[j];
                    somber_smithing_stones[j]=nullptr;
                }
                somber_weapons[i]->up(somber_weapons[i]->get_level()+1);
                
            }
            cout<<"Upgrade "<<initial_name<<" to "<<somber_weapons[i]->expand_name<<" Successfully."<<endl;
        }
    }
    if(have_weapon==false){
        cout<<"You don't have the right!"<<endl;
        return;
    }

}
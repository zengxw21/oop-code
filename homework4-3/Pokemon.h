#include<string>
#include<iostream>
using namespace std;
class Pokemon
{
protected:
    int tot_hp, hp, atk;
    string name;
public:
    Pokemon(int hp, int atk, string name);
    Pokemon();
    virtual void use_skill(int idx, Pokemon* target)=0;// 对目标target使用idx号技能
    virtual void hurt(int dmg, Pokemon* from)=0;// 受到来自from的dmg点伤害时的反应
    string get_name();    // 获取宝可梦名字
    bool alive();     // 宝可梦是否存活
    int get_hp();     // 获取生命值
    int get_atk();  // 获取攻击力
    ~Pokemon();
};
class Squirtle:public Pokemon{
public:
    Squirtle(int hp, int atk, string name):Pokemon(hp,atk,name){}
    ~Squirtle(){}
    void use_skill(int idx,Pokemon* target){
        if(idx==0){
            hp=min((hp+tot_hp/5),tot_hp);
            cout<<get_name()<<" used Regen"<<endl;
        }
        if(idx==1){
            cout<<get_name()<<" used Splash to "<<target->get_name()<<endl;
            target->hurt(atk,this);
            
        }
    }
    void hurt(int dmg,Pokemon*from){
        int final_dmg;
        if(hp<=tot_hp/5){
            hp-=max(1,dmg/2);//
            final_dmg=max(1,dmg/2);
        }
        else{
            final_dmg=dmg;
            hp-=final_dmg;
        }
        cout<<get_name()<<" received "<<final_dmg<<" damage from "<<from->get_name()<<endl;
    }
};
class Charizard:public Pokemon{
public:
    int fire;
    Charizard(int hp,int atk,string name):Pokemon(hp,atk,name){
        fire=1;
    }
    ~Charizard(){}
    void use_skill(int idx,Pokemon* target){
        if(idx==0){
            fire+=1;
            atk*=2;
            hp-=fire*10;
            cout<<get_name()<<" used Ignite"<<endl;
            cout<<get_name()<<" received "<<fire*10<<" damage from "<<get_name()<<endl;
        }
        if(idx==1){
            cout<<get_name()<<" used Flame to "<<target->get_name()<<endl;
            target->hurt(atk,this);
            
        }
    }
    void hurt(int dmg,Pokemon *from){
        cout<<get_name()<<" received "<<dmg<<" damage from "<<from->get_name()<<endl;
        if(dmg>=10){
            int ref=max(1,dmg/5);
            from->hurt(ref,this);
        }
        hp-=dmg;
    }
};

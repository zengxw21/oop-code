#include<iostream>
#include"smithing_stone.h"
#include"somber_smithing_stone.h"
#include<string>
using namespace std;
SomberSmithingStone::SomberSmithingStone(int i):SmithingStone(i){
        cout<<"Somber smithing stone "<<i<<" was created."<<endl;
    }
void SomberSmithingStone::echo(int i){//i stands for amount
        add_amount(i);
        int thelevel=get_level();
        cout<<"Somber smithing stone "<<thelevel<<" was added with "<<i<<"."<<endl;
    }
SomberSmithingStone::~SomberSmithingStone(){
        cout<<"Somber smithing stone "<<get_level()<<" was destroyed."<<endl;
    }
void SomberSmithingStone::substract(int sub){
        add_amount(sub);
        cout<<"Somber smithing stone "<<get_level()<<" was substracted with "<<0-sub<<"."<<endl;
    }
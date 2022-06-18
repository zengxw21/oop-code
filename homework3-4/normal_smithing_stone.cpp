#include"normal_smithing_stone.h"
#include"smithing_stone.h"
#include<iostream>
using namespace std;

NormalSmithingStone::NormalSmithingStone(int i):SmithingStone(i){
        cout<<"Normal smithing stone "<<i<<" was created."<<endl;
    }
void NormalSmithingStone::echo(int i){//i stands for amount
        SmithingStone::add_amount(i);
        int thelevel=get_level();
        cout<<"Normal smithing stone "<<thelevel<<" was added with "<<i<<"."<<endl;
    }
NormalSmithingStone::~NormalSmithingStone(){
        cout<<"Normal smithing stone "<<get_level()<<" was destroyed."<<endl;
    }
void NormalSmithingStone::substract(int sub){
        add_amount(sub);
        cout<<"Normal smithing stone "<<get_level()<<" was substracted with "<<0-sub<<"."<<endl;
    }
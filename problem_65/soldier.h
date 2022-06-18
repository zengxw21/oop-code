#include"card.h"
#include<string>
using namespace std;

class Soldier:public Card{
public:
    
    Soldier():Card("soldier"){}
    int battle(Card * other){
        string tmp = other->name();
        if(tmp == "beggar"){
            return 1;
        }
        else if (tmp == "king"){
            return -1;
        }
        else
        return 0;
    }
};
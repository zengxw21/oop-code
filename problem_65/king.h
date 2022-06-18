#include"card.h"
#include<string>
using namespace std;

class King:public Card{
public:
    
    King():Card("king"){}
    int battle(Card* other){
        string tmp = other->name();
        if(tmp == "soldier")
        return 1;
        else if(tmp == "beggar")
        return -1;
        else
        return 0;
    }
};
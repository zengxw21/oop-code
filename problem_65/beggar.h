#include"card.h"
#include<string>
using namespace std;

class Beggar:public Card{
public:
    Beggar():Card("beggar"){}
    int battle(Card* other){
        string tmp = other->name();
        if(tmp == "king")
        return 1;
        else if(tmp == "soldier")
        return -1;
        else
        return 0;
    }
};
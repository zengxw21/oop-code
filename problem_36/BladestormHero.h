#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
public:	// TODO
	BladestormHero(Hero* h){
		blade ++;
		auto tmp = dynamic_cast<SkilledHero*>(h);
		if(tmp){
			blade +=tmp->blade;
			avatar += tmp->avatar;
		}
	}
};

//画图出来就好做了。
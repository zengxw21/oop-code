#pragma once
#include "SkilledHero.h"

class AvatarHero : public SkilledHero {
public:	// TODO
	AvatarHero(Hero* h){
		avatar ++;
		auto tmp = dynamic_cast<SkilledHero*>(h);
		if(tmp){
			blade +=tmp->blade;
			avatar += tmp->avatar;
		}
	}
};
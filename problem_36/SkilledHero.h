#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
public:
	int avatar = 0;
	int blade = 0;// TODO
	void getSkill(name2Level& skillmap){
		skillmap["Bladestorm"] = blade;
		skillmap["Avatar"] = avatar;
	}
};
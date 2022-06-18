#pragma once

#include"weapon.h"

class SomberWeapon:public Weapon{
public:
    static int num;
    string expand_name;
    using Weapon::get_name;
    using Weapon::get_level;
    SomberWeapon(string name);
    ~SomberWeapon();
    void up(int lv);
};
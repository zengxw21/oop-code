#pragma once

#include"weapon.h"

class NormalWeapon:public Weapon{
public:
    static int num;
    string expand_name;
    using Weapon::get_name;
    using Weapon::get_level;
    using Weapon::upgrade;
    NormalWeapon(string name);
    ~NormalWeapon();
    void up(int lv);
};
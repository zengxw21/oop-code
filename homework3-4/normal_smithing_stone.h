#pragma once

#include"smithing_stone.h"

class NormalSmithingStone:public SmithingStone{
public:
    using SmithingStone::add_amount;
    using SmithingStone::get_level;
    using SmithingStone::greater_equal;
    
    NormalSmithingStone(int i);
    void echo(int i);
    ~NormalSmithingStone();
    void substract(int sub);
    
};
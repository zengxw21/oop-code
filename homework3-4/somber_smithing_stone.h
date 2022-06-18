#pragma once

#include"smithing_stone.h"

class SomberSmithingStone:public SmithingStone{
public:
    using SmithingStone::add_amount;
    using SmithingStone::get_level;
    using SmithingStone::greater_equal;
    SomberSmithingStone(int i);
    void echo(int i);
    ~SomberSmithingStone();
    void substract(int sub);
};
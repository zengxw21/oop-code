#pragma once
#include"animal.h"
#include<vector>
using namespace std;

void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone){
    auto bird = dynamic_cast<Bird*> (animal);
    auto dog = dynamic_cast<Dog*> (animal);//转换失败则返回空指针
    if(bird){
        auto b = std::move(*bird);
        birdzone.push_back(std::move(b));
    }
    if(dog){
         auto d = std::move(*dog);
         dogzone.push_back(std::move(d));
    }
}
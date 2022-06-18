#include"animal.h"
#include<vector>
void action(Animal* animal,
 std::vector<Dog> & dogzone, std::vector<Bird> & birdzone){
     auto d=dynamic_cast<Dog*> (animal);
     auto b=dynamic_cast<Bird*> (animal);
     if(d){
        Dog dg=std::move(*d);
        dogzone.push_back(std::move(dg));
     }
     if(b){
        Bird bd=std::move(*b);
        birdzone.push_back(std::move(bd));//必须指明std::move，因为拷贝构造是已经删除的函数，不能用
     }
 }
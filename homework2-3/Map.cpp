#include "Map.h"
Map::Map(int n){
    data=new Pair[n];
    sz=0;
}
int Map::size(){
   
    return sz;
}
Map::~Map(){
    delete[]data;
}
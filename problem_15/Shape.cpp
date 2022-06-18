#include"Shape.h"
using namespace std;

  

double Rectangle::getArea(){
     return width * height;
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}
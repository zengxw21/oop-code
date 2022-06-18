#pragma once 
using namespace std;

class Shape{
public:
virtual  double getArea() = 0;
};

class Rectangle:public Shape{
public:
    double width;
    double height;
    Rectangle(double _w,double _h):width(_w),height(_h){}
    double getArea();
    //~Rectangle(){}//子类的析构函数必须实现 undefined reference to vtable for
};

class Circle:public Shape{
public:
    double radius;
    Circle(double r):radius(r){}
    double getArea();
    //~Circle(){}
};
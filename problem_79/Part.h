#pragma once


class Part{
public:
    int id;
    Part(int _id):id(_id){}
    Part(){}
};

class Robot{
public:
    Part* parts;

};
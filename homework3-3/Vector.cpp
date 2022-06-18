#include"Vector.h"
#include"Node.h"
using namespace std;
Vector::Vector(int n){
    array=new Node [n];//此处开辟动态数组
    capacity=n;
    len=0;
}
Vector::~Vector(){
    len=0;capacity=0;
     delete[]array;
}
Vector::Vector(const Vector & other){
    len=other.len;
    capacity=other.capacity;
    array=new Node[capacity];
    for(int i=0;i<len;i++){
        array[i]=other.array[i];
    }
    
}
Vector::Vector(Vector && other){
    array=other.array;
    other.array=nullptr;
    len=other.len;
    other.len=0;
    capacity=other.capacity;
    other.capacity=0;
}
Vector & Vector::operator=(const Vector& other){//这里有可能不对
    if(this!=&other){
        if(array)delete[]array;
        len=other.len;
        capacity=other.capacity;
        array=new Node[other.capacity];
        for(int i=0;i<len;i++){
            array[i]=other.array[i];
        }
    }
    return *this;
}
Vector & Vector::operator=(Vector&& other){
        delete[]array;
        this->array=other.array;
        other.array=nullptr;
        this->len=other.len;//移动语义
        other.len=0;
        capacity=other.capacity;
        other.capacity=0;
    
    return *this;
}
Node& Vector::operator [] (int pos){
    return array[pos];
}
void Vector::append(int value){
    Node tmp(value);
    array[len]=std::move(tmp);
    len++;
}
void Vector::insert(int pos,int value){
    for(int i=len;i>=pos+1;i--){
        array[i]=std::move(array[i-1]);
    }
    Node tmp(value);
    array[pos]=std::move(tmp);
    len++;
}
void Vector::swap(int pos1,int pos2){
    Node tmp(std::move(array[pos1]));
    array[pos1]=std::move(array[pos2]);
    array[pos2]=std::move(tmp);
    //tmp.~Node();
}
void Vector::dilatation(){
   Node* new_array=new Node[2*capacity];
   for(int i=0;i<len;i++){
       new_array[i]=std::move(array[i]);
   }
   if(array)delete[]array;//疑惑
   this->array=new_array;
   new_array=nullptr;
   capacity*=2;
}
int Vector::getlen(){
    return len;
}
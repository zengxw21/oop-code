#pragma once
#include <list>
#include <iostream>
#include <memory>
#include "CustomClass.h"
using namespace std;
class Object;
class Content
{public:
	virtual void output(std::ostream& out){ //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	void output( std::ostream& out){ //???
		out << x;//changed
	}
	IntContent& operator+=(int y){
		x += y;
		return *this;
	}
};
class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	void output( std::ostream& out){  //???
		out << x;//changed
	}
	StringContent& operator+=(const string& y){
		x += y;
		return *this;
	}
};
// The following codes are not working
 class VectorContent: public Content
{
 private:
	
 	std::vector<Object> x; //Object is not defined???
 public:
 	VectorContent(const std::vector<Object>& _x): x(_x) {}
	Object& operator[](int index){
		return x[index];
	}
};
class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content> pt;
public:
	Object() {}
	Object(int x) {
		pt = make_shared<IntContent>(IntContent(x)); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x){
		pt = make_shared<StringContent>(StringContent(x));
	}
	// The following codes are not working
	Object(const std::vector<Object> &x){
	 	pt = make_shared<VectorContent>(VectorContent(x));
	 }
	Object(const CustomClass &x){
		pt = make_shared<CustomContent>(CustomClass(x));
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y){//向下类型转换？
		auto p = dynamic_pointer_cast<IntContent> (pt);
		p->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		auto p = dynamic_pointer_cast<StringContent> (pt);
		p->operator+=(y);
		return *this;
	}

	//need more operators......
	Object& operator[](int x){
		auto p = dynamic_pointer_cast<VectorContent> (pt);
		return p->operator[](x);
		
	}
};

//注意类之间的“自锁”，某些情况下（比如不用提前实例化对象）可以用前置声明避免这一问题。

#include <iostream>
#include "Example.h"

using namespace std;

int Example::count=1;// (2)

Example::Example(int data) {
	number=count;cout<<"Example #"<<number<<" is created"<<endl;count++;hisdata=data_[number-1];// (3)
}

void Example::getData() {
	cout<<"The data of Example #"<<number<<" is "<<hisdata<<endl;// (4)
}

Example::~Example() {
	cout<<"Example #"<<number<<" is destroyed"<<endl;// (5)
}
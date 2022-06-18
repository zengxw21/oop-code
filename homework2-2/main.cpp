#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	static Example e6(6);for(int i=0;i<n;i++) e[i]->getData();for(int i=0;i<n;i++) e[i]->~Example();e6.getData();// (6)
	
	cout << "--------create_example is over--------\n";
}

Example e1(1);// (7)

int main() {

	cout << "--------main_function is ready--------\n";

	Example e2(2);// (8)
		
	create_example(3);
	
	Example e7(7);e1.getData();e2.getData();e7.getData();// (9)

	cout << "--------main_function is over---------\n";

	return 0;
}

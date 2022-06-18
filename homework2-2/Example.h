#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	int data_[7]={23,233,0,1,2,2333,23333};
	static int count;// (1)
	int number;	int hisdata;	
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif
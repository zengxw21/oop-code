#pragma once
#include <list>
#include <memory>
using namespace std;
class MyList
{
public:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}


	MyList(): pt(new std::list<int>()){
		left = pt->begin();
		right = pt->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	void append(int i){
		pt->insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		right ++;// DEBUG !! Why I can't insert i??
	}

	int& operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}

	friend ostream& operator<<(std::ostream& out,MyList& my);

	

	MyList operator()(int i,int j){
		MyList tmp;
		tmp.pt = this->pt;
		tmp.left = this->forward(i);
		tmp.right = this->forward(j);
		return tmp;
	}
};

 ostream& operator<<(std::ostream& out,MyList& my){
		out << "[";
		if (my.left != my.right){
			auto now = my.left;
			out << *now;
			now ++;
			for(; now != my.right; now++){
				out << "," << *now;
			}
		}
		out << "]";
		return out;
}
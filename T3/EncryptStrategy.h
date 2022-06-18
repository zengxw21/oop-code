#pragma once
# include <string>
using namespace std;

class EncryptStrategy
{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy:public EncryptStrategy{
public:
	string encode(string mes){
		string tmp;
		for (int i = 0; i < (int)mes.length();i++){
			tmp += mes[i];
			tmp += '#';
		}
		return tmp;
	}
};

class InvertStrategy:public EncryptStrategy{
public:
	string encode(string mes){
		string tmp;
		for (int i = (int)mes.length() - 1; i >= 0;i--){
			tmp += mes[i];
		}
		return tmp;
	}
};

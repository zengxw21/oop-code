#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>


using namespace std;

// Change this file as you want or add more files

class Vocabulary
{
private:
    map<string,int> m;//记录哪些单词出现过// Choose a proper container from STL.
    int index=0;
public:
    vector<int> insertSentReturnIds(string sentence){
        istringstream is(sentence);
        vector<int> sentenceid;
        
        string tmp;
        
        while(is>>tmp){
            if(m.count(tmp)==0){//the word hasnt appeared
                index++;
                m[tmp]=index;//insert the value
                
            }
            sentenceid.push_back(m[tmp]);
        }
        return sentenceid;
        //Enter your code here.
        //This function should build vocabulary and at the same time return a sentence encoding.
    }
};


class DataLoader{
private:
    vector<int> _rand_order;
    int batch_size=0;
    vector<vector<int>> dataset;//Enter your code here
    vector<vector<int>> processed_dataset;
    vector<vector<vector<int>>> matrix ;
    
public:
    void setBatchSize(int N){
        this->batch_size = N; // can also change
        int size=_rand_order.size();
        int count=size/N;
        int remain=size-count*N;//看分批后是否还剩下
        
        matrix.clear();
        for(int i=0;i<count;i++){
            vector<vector<int>> tmp;
            int max_size=0;
            for(int j=0;j<N;j++){
                int index=i*N+j;
                int cur_size=processed_dataset[index].size();
                max_size=max(max_size,cur_size);
            }
            for(int j=0;j<N;j++){
                int index=i*N+j;
                int cur_size=processed_dataset[index].size();
                vector<int> add_zero=processed_dataset[index];
                for(int k=0;k<max_size-cur_size;k++){
                    add_zero.push_back(0);
                }
                tmp.push_back(add_zero);
            }
            matrix.push_back(tmp);
        }
        
        vector<vector<int>> tmp;
        int max_size=0;
        for(int i=count*N;i<size;i++){
            max_size=max(max_size,(int)processed_dataset[i].size());
            
           
        }
        
        for(int i=count*N;i<size;i++){
            auto v=processed_dataset[i];
            
            while(v.size()<max_size){
                v.push_back(0);
            }
            //终于明白：如果写for(int j=0;j<max_size-v.size();j++),因为再循环中，往v中补0，导致v的size
            //也在变大，最后导致补的0少一半！
            //启示：循环里面不应该有变化量！！！
            tmp.push_back(v);
        }
        if(tmp.empty()==false)
        matrix.push_back(tmp);
    }

    void setOrder(vector<int>& x){
        _rand_order = x; // can also change
        int size=_rand_order.size();
        processed_dataset.clear();
        for(int i=0;i<size;i++){
            int tmp=_rand_order[i];
            processed_dataset.push_back(dataset[tmp]);
        }
    }

    void addData(vector<int> sent_encoding){
        dataset.push_back(sent_encoding);//Enter you code here;
    }

    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = vector<vector<int>>;
        using reference         = const std::vector<vector<int>>&;
       
        std::vector<vector<int>>* ptr;
        Iterator(){ptr=nullptr;}
        Iterator(vector<vector<int>>* _p){ptr=_p;}
        std::vector<vector<int>>& operator*() const{return *ptr;}
        std::vector<vector<int>>* operator->() const{return ptr;}

        Iterator& operator++(){
            ptr++;
            return *this;
        }
        bool operator==(const Iterator& it)const{
            return ptr==it.ptr;
        }
        bool operator!=(const Iterator& it)const{
            return ptr!=it.ptr;
        }
        private:
        

    };

    Iterator begin() {
        //Enter your code here.
        vector<vector<int>>* p=&matrix[0];
        Iterator it(p);
        return it;
    }
    Iterator end() {
        //end应该指向最后一个元素的下一位！！！
        //end()指向最后一个元素，将导致对最后一个元素无法进行操作！！！因为遍历里面判断的是!=end()
        int index=matrix.size()-1;
        auto tmp=&matrix[index]+1;
        Iterator it(tmp);
        return it;
    }

};

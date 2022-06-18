 int capacity;
    struct ele
    {
        bool con=false;
        T2 val;
    };
    ele *array;
    Hashtable(int n){
        
        array=new ele[n];
        capacity=n;
    }
    ~HashTable(){
        delete[]array;
    }
    void addItem(const T1 &key, const T2 &value){
        array[(key)].val=value;
        array[(key)].con=true;
    }
    void removeItem(const T1 &key){
        array[(key)].con=false;
    }
    T2 *findByKey(const T1 &key){
        if(array[(key)].con=false){
            return nullptr;
        }
        T2 * tmp = &array[(key)].val;
        return tmp;
    }
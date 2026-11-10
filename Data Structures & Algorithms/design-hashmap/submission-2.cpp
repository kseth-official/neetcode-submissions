class MyHashMap {
public:
    MyHashMap() {
        v.assign(capacity+1,-1);
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key]=-1;
    }

private:
    const int capacity = 1000000;
    vector<int> v;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
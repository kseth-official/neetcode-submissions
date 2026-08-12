class TreeMap {

public:
    TreeMap() {
        
    }

    void insert(int key, int val) {
        tm[key]=val;
    }

    int get(int key) {
        if (tm.count(key) <= 0)
            return -1;
        return tm[key];
    }

    int getMin() {
        if (tm.size()==0) 
            return -1;
        return tm.begin()->second;
    }   

    int getMax() {
        if (tm.size()==0) 
            return -1;
        return tm.rbegin()->second;
    }

    void remove(int key) {
        tm.erase(key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> keys;
        for (const auto& row: tm) {
            keys.push_back(row.first);
        }
        return keys;
    }
private:
    map<int, int> tm;
};

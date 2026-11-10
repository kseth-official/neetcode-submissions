struct ListNode {
    int k,v;
    ListNode* next;

    ListNode() {}
    ListNode(int key, int val): k(key), v(val), next(nullptr) {}
    ListNode(int key, int val, ListNode* n): k(key), v(val), next(n) {}
};

class MyHashMap {
public:
    MyHashMap() {
        v.assign(capacity,nullptr);
    }
    
    void put(int key, int value) {
        auto* cn = v[hash(key)];
        if (cn == nullptr) {
            v[hash(key)] = new ListNode(key, value);
            return;
        }
        while (cn != nullptr) {
            if (cn->k == key) {
                cn->v = value;
                return;
            }
            if (cn->next == nullptr) break;
            cn = cn->next;
        }
        cn->next = new ListNode(key, value);
    }
    
    int get(int key) {
        auto* cn = v[hash(key)];
        while (cn != nullptr) {
            if (cn->k == key)
                return cn->v;
            cn=cn->next;
        }
        return -1;
    }
    
    void remove(int key) {
        auto* cn = v[hash(key)];
        if (cn == nullptr)
            return;
        if (cn->k == key) {
            v[hash(key)] = cn->next;
            delete cn;
            return;
        }
        while (cn->next != nullptr) {
            if (cn->next->k == key) {
                auto* d = cn->next;
                cn->next = cn->next->next;
                delete d;
                return;
            }
            cn = cn->next;
        } 
    }

private:
    const int capacity = 1000;
    vector<ListNode*> v;

    int hash(int v) {
        return v % capacity;
    }
};
const unsigned int HASHSET_SIZE = 20000;
struct Node {
    int key;
    Node* next;

    Node(int k): key(k) {}
    Node(int k, Node* nn) : key(k), next(nn) {}
    
    ~Node() {
        delete next;
    }
};

class MyHashSet {
public:
    vector<Node*> set;

    MyHashSet() {
        set.resize(HASHSET_SIZE);
    }

    int hash(int key) {
        return key % HASHSET_SIZE;
    }
    
    void add(int key) {
        if (!contains(key)) {
            int index = hash(key);
            Node* nn = new Node(key, nullptr);

            if (set[index] == nullptr) {
                set[index] = nn;
                return;
            }

            // Bucket contains existing keys -> iterate through all of them to find last
            Node* cn = set[index];
            while (cn->next != nullptr) {
                cn = cn->next;
            }
            cn->next = nn;
        }
    }
    
void remove(int key) {
    int index = hash(key);
    Node* cn = set[index];
    Node* pv = nullptr;
    while (cn != nullptr && cn->key != key) {
        pv = cn;
        cn = cn->next;
    }
    if (cn == nullptr) return; // key not found

    if (pv == nullptr) { // removing head
        set[index] = cn->next;
    } else {
        pv->next = cn->next;
    }
    cn->next = nullptr; // prevent recursive deletion of the rest
    delete cn;
}

    
    bool contains(int key) {
        int index = hash(key);

        if (set[index] == nullptr) {
            return false;
        }

        Node* cn = set[index];
        while (cn != nullptr) {
            if (cn->key == key)
                return true;
            cn = cn->next;
        }
        return false;
    }

    ~MyHashSet() {
        for (const auto& bucket: set) {
            delete bucket;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
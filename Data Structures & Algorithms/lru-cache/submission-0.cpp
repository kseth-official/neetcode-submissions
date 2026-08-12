struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(Node* nxt, Node* prv, int k, int v): key(k), value(v), next(nxt), prev(prv) {}
    Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    Node* head = nullptr; // LRU
    Node* tail = nullptr; // MRU
    unordered_map<int, Node*> addrMap;

    // Move a node to the tail (MRU)
    void setMRU(Node* curr) {
        if (curr == tail) return; // Already MRU

        // Unlink curr
        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next; // curr was head

        if (curr->next) curr->next->prev = curr->prev;

        // Insert at tail
        curr->prev = tail;
        curr->next = nullptr;
        if (tail) tail->next = curr;
        tail = curr;
        if (!head) head = curr;
    }

    // Add a new node at the tail (MRU)
    void setMRUNewNode(Node* curr) {
        curr->prev = tail;
        curr->next = nullptr;
        if (tail) tail->next = curr;
        tail = curr;
        if (!head) head = curr;
    }

    // Remove head (LRU)
    void evictLRU() {
        if (!head) return;
        Node* lru = head;
        addrMap.erase(lru->key);

        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // List is now empty

        delete lru;
    }

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (addrMap.find(key) == addrMap.end())
            return -1;
        Node* curr = addrMap[key];
        setMRU(curr);
        return curr->value;
    }

    void put(int key, int value) {
        if (addrMap.find(key) != addrMap.end()) {
            Node* curr = addrMap[key];
            curr->value = value;
            setMRU(curr);
            return;
        }
        if (addrMap.size() == cap) {
            evictLRU();
        }
        Node* nn = new Node(key, value);
        addrMap[key] = nn;
        setMRUNewNode(nn);
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

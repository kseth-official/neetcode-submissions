// Implementation using open-addressing that is more cache-efficient since it avoids pointers.
class HashTable {
public:
    HashTable(int capacity) {
        ht.resize(capacity);
    }

    void insert(int key, int value) {
        // Check if adding a value will cause load factor to exceed threshold
        if (static_cast<float>(size + 1) / static_cast<float>(ht.size()) >= LOAD_FACTOR) {
            resize();
        }
        for (int i = 0; i < ht.size(); i++) {
            int idx = hash(key, i);
            auto& bucket = ht[idx];
            if (bucket.state == State::OCCUPIED && bucket.key == key) {
                bucket.value = value;
                return;
            }
            if (bucket.state != State::OCCUPIED) {
                bucket.state = State::OCCUPIED;
                bucket.key = key;
                bucket.value = value;                        
                size++;
                return;
            }
            // Occupied but key not same. Can't insert here. Keep looking.
        }
    }

    int get(int key) {
        for (int i = 0; i < ht.size(); i++) {
            int idx = hash(key, i);
            auto& bucket = ht[idx];
            if (bucket.state == State::OCCUPIED && bucket.key == key) {
                return bucket.value;
            }
            if (bucket.state == State::EMPTY) {
                // Key does not exist
                return -1;
            }
            // Deleted, so continue   
        }

        // Should never reach here. It means everything was marked deleted and key doesn't exist.
        // Inserts should have handled auto-resizing by now.
        return -1;
    }

    bool remove(int key) {
        for (int i = 0; i < ht.size(); i++) {
            int idx = hash(key, i);
            auto& bucket = ht[idx];
            if (bucket.state == State::OCCUPIED && bucket.key == key) {
                bucket.state = State::DELETED;
                size--;
                return true;
            }
            if (bucket.state == State::EMPTY) {
                // Key does not exist
                return false;
            }
            // Deleted, so continue   
        }

        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return ht.size();
    }

    void resize() {
        vector<Bucket> old_ht = ht;

        int n_capacity = old_ht.size() * 2;
        ht.clear();
        ht.resize(n_capacity);
        size = 0;

        // Reinsert all previously occupied entries for rehashing after resize
        for (auto& bucket: old_ht) {
            if (bucket.state == State::OCCUPIED) {
                insert(bucket.key, bucket.value);
            }
        }
    }
private:
    // Hash function for linear probing, i is attempt
    int hash(int key, int i) {
        return (hash_p(key) + i) % ht.size();
    }

    // Primary hash function
    int hash_p(int key) {
        return key % ht.size();
    }

    enum State {
        EMPTY,
        OCCUPIED,
        DELETED
    };

    struct Bucket {
        int key;
        int value;
        State state;

        Bucket() {
            key = -1;
            state = State::EMPTY;
            // Value is okay empty
        }
    };

    int size = 0;
    static constexpr float LOAD_FACTOR = 0.5;
    vector<Bucket> ht;
};
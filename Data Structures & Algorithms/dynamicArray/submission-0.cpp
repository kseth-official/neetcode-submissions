class DynamicArray {
public:
    DynamicArray(int capacity) {
        m_array.reserve(capacity);
    }

    int get(int i) {
        return m_array[i];
    }

    void set(int i, int n) {
        m_array[i] = n;
    }

    void pushback(int n) {
        if (m_array.size() == m_array.capacity())
            resize();
        m_array.push_back(n);
    }

    int popback() {
        auto value = m_array.back();
        m_array.pop_back();
        return value;
    }   

    void resize() {
        m_array.reserve(m_array.capacity() * 2);
    }

    int getSize() {
        return m_array.size();
    }

    int getCapacity() {
        return m_array.capacity();
    }

private:
    vector<int> m_array;
};

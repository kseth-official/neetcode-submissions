class Deque {
public:
    Deque() {
        
    }

    bool isEmpty() {
        return q.empty();
    }

    void append(int value) {
        q.push_back(value);
    }

    void appendleft(int value) {
        q.push_front(value);
    }

    int pop() {
        if (isEmpty())
            return -1;
        int value = q.back();
        q.pop_back();
        return value;
    }

    int popleft() { 
        if (isEmpty())
            return -1;
        int value = q.front();
        q.pop_front();
        return value;
    }
private:
    deque<int> q;
};

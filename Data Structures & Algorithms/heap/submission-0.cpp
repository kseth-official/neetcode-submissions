class MinHeap {
public:
    MinHeap() {}

    void push(int val) {
        mh.push(val);
    }

    int pop() {
        if (mh.empty())
            return -1;
        int value = mh.top();
        mh.pop();
        return value;
    }

    int top() {
        if (mh.empty())
            return -1;
        return mh.top();
    }

    void heapify(const vector<int>& arr) {
        mh = priority_queue<int, vector<int>, greater<int>>(arr.begin(), arr.end());
    }

private:
    priority_queue<int, vector<int>, greater<int>> mh;
};

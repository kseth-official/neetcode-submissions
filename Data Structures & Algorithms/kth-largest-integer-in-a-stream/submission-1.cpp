class KthLargest {
public:

    priority_queue<int> *_pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        _pq = new priority_queue<int>(nums.begin(), nums.end());
    }
    
    int add(int val) {
        _pq->push(val);
        vector<int> removed;
        for (int i = 0;i < _k-1; i++) {
            int val = _pq->top();
            removed.push_back(val);
            _pq->pop();
        }

        int result = _pq->top();

        // logic to reinsert removed values
        for (const auto& num: removed) {
            _pq->push(num);
        }

        return result;
    }

    ~KthLargest() {
        delete _pq;
    }
};

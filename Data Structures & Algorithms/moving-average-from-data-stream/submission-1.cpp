class MovingAverage {
public:
    int ws;
    long long cs;
    deque<int> q;

    MovingAverage(int size) {
        ws=size;
        cs=0;
    }
    
    double next(int val) { 
        q.push_back(val);
        cs+=val;
        while (q.size() > ws) {
            cs -= q.front();
            q.pop_front();
        }
        return static_cast<double>(cs) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

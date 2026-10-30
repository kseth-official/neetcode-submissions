class MovingAverage {
public:
    int ws;
    int ps;
    double pa;
    deque<int> q;

    MovingAverage(int size) {
        ws=size;
        pa=0;
        ps=0;
    }
    
    double next(int val) { 
        q.push_back(val);
        bool flag = false;
        int evicted;
        while (q.size() > ws) {
            flag = true;
            evicted = q.front();
            q.pop_front();
        }
        if (flag)
            pa = (pa * ps - evicted + val) / q.size();
        else
            pa = (pa * ps + val) / q.size();
        ps = q.size();
        return pa;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

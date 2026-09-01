class MedianFinder {
public:
    // contains first half
    priority_queue<int, vector<int>> maxh;

    // contains second half
    priority_queue<int, vector<int>, greater<int>> minh;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxh.empty()) {
            maxh.push(num);
            return;
        }

        int midL = maxh.top();

        if (num <= maxh.top()) {
            maxh.push(num);
            if (maxh.size() > minh.size() + 1) {
                int t = maxh.top();
                maxh.pop();
                minh.push(t);
            }
            return;
        }

        minh.push(num);
        if (minh.size() > maxh.size() + 1) {
            int t = minh.top();
            minh.pop();
            maxh.push(t);
        }
        // left and right should differ by no more than 2
    }
    
    double findMedian() {
        int n = maxh.size();
        int m = minh.size();

        if ((n + m) % 2 != 0) {
            if (n > m) {
                return static_cast<double>(maxh.top());
            } 
            return static_cast<double>(minh.top());
        }

        return (static_cast<double>(maxh.top()) + static_cast<double>(minh.top())) / 2;
    }
};

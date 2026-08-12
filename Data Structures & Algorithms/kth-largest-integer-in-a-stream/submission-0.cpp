class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int storedK;
    
    KthLargest(int k, vector<int>& nums) {
        storedK = k;
        for (const auto& num: nums) {
            minHeap.push(num);
            if (minHeap.size() > storedK)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > storedK)  
            minHeap.pop();
        return minHeap.top();
    }
};

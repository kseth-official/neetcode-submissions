class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        int kthLar;
        for (int i=0;i<k;i++) {
            kthLar = pq.top();
            pq.pop();
        }
            
        return kthLar;
    }
};

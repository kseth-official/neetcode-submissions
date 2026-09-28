class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int i=0;i<nums.size();i++) {
            nums[i] = a * nums[i]*nums[i] + b * nums[i] + c;
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};
